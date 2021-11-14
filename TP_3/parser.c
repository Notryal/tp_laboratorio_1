#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	//resto del codigo es donde parseo, desarmo, parse a los empleados en lineas
	//esto lo hago para que no me quede gigante la funcione de leer archivo texto
	int rtn = -1;
	char auxId[2000];
	char auxNombre[2000];
	char auxHoras[2000];
	char auxSueldo[2000];
	int cantidad = 0;
	Employee* auxiliar = NULL;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		do
		{
			cantidad = fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo); //excluyo las comas, hago mascaras

			if(cantidad==4)
			{
				auxiliar = employee_newParametros(auxId,auxNombre,auxHoras,auxSueldo);

				if(auxiliar!=NULL)
				{
					ll_add(pArrayListEmployee, auxiliar);
					rtn=0;
				}
				else
				{
					employee_delete(auxiliar);
				}
			}

		}
		while(!feof(pFile)); //find end of file, mientras que no llege al final
	}

    return rtn;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	Employee* auxiliar = NULL;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		do
		{
			auxiliar = employee_new();

			if(auxiliar!=NULL)
			{
				if(fread(auxiliar,sizeof(Employee),1,pFile))
				{
					ll_add(pArrayListEmployee,auxiliar);
					rtn=0;
				}
				else
				{
					employee_delete(auxiliar);
				}
			}
		}while(!feof(pFile));
	}

    return rtn;
}


int parser_IdFromText(FILE* pFile , LinkedList* pArrayListEmployee, int* id)
{
	int isOk = -1;
	char idTxt[128];
	int idInt;
	int cantidad = 0;
	int header=1;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		do
		{
			cantidad = fscanf(pFile,"%[^\n]\n",idTxt);

			if((cantidad==1) && (header!=1))
			{
				isOk = 0;
				idInt = atoi(idTxt);

				if(idInt>*id)
				{
					*id=idInt;
				}
			}
			else
			{
				header=0;
			}
		}
		while(!feof(pFile));
	}

    return isOk;
}
