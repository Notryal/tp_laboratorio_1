#include "input.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


Employee* employee_new(){
	Employee* pEmpleado = NULL;
	int id;
	int sueldo;
	int horas;
	char nombre[128];

	id=0;
	horas=0;
	sueldo=0;
	strcpy(nombre,"\0");

	pEmpleado = (Employee*) malloc(sizeof(Employee)); // void employee_delete(Employee* this)

	//void es mi comodin, lo transformo a puntero estructura

	if(pEmpleado!=NULL)
	{
		employeInt(pEmpleado,id,nombre,horas,sueldo);
	}

	return pEmpleado;
}


Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr){

	Employee* AuxEmpleado = NULL;

	if(idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
	{
		AuxEmpleado = employee_new(); //lleno mi estructura con empleado, aloco memoria

		if(AuxEmpleado!=NULL)
		{
			if((employeChar(AuxEmpleado,idStr,nombreStr,horasTrabajadasStr,sueldoStr))!=0)
			{
				employee_delete(AuxEmpleado); //libero el puntero la memoria
			}
		}
	}

	return AuxEmpleado; //devuelvo mi estructura llena con empleado

}

void employee_delete(Employee* this){
	//int rtn = -1;

	if(this!=NULL)
	{
		free(this);
		this=NULL;
		//rtn=0;
	}

	//return rtn;
}

int employee_add(LinkedList* empleados, int* id)
{
	int rtn = -1;
	char respuesta[4];
	int auxiliarID;
	char auxiliarNombre[200];
	int auxiliarHoras;
	int auxiliarSueldo;
	Employee* auxEmpleado = NULL;

	if(empleados!=NULL && id!=NULL)
	{
		auxEmpleado = employee_new();

		if(auxEmpleado!=NULL)
		{
			if((!(utn_getString(auxiliarNombre,200,3,"\nIngrese el nombre: ","\nError! 200 caracteres, no numeros: ")) &&
				!(utn_getInt(&auxiliarHoras,1,500,3,"\nIngrese las horas trabajadas: ","\nError! : ")) &&
				!(utn_getInt(&auxiliarSueldo,1,50000,3,"\nIngrese sueldo: ","\nError! reingrese: "))))
			{
				SizeString(auxiliarNombre);
				auxiliarID = *id;
				auxiliarID+=1;

				if(!employeInt(auxEmpleado,auxiliarID,auxiliarNombre,auxiliarHoras,auxiliarSueldo))
				{
					employee_printOneEmployee(auxEmpleado);
					utn_getString(respuesta,sizeof(respuesta),3,"\n¿Esta seguro que desea guardar este empleado?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n");

					if(!(stricmp(respuesta,"si")))
					{
						ll_add(empleados, auxEmpleado);
						*id=auxiliarID;
						rtn=0;
					}
					else
					{
						employee_delete(auxEmpleado);
					}
				}
			}
			else
			{
				puts("\nReintente nuevamente");
			}
		}
		else
		{
			puts("No hay espacio para un nuevo empleado");
		}
	}

	return rtn;
}


int employee_printOneEmployee(Employee* this)
{
	int rtn = -1;
	int auxiliarID;
	char auxiliarNombre[128];
	int auxiliarHoras;
	int auxiliarSueldo;

	if(this!=NULL)
	{
		if(!employeeGets(this,&auxiliarID,auxiliarNombre,&auxiliarHoras,&auxiliarSueldo))
		{
			printf("%d\t%-10s\t%d\t%d\n",auxiliarID
										,auxiliarNombre
										,auxiliarHoras
										,auxiliarSueldo);
			rtn=0;
		}
		else
		{
			printf("Error para mostrar el empleado");
		}
	}

	return rtn;
}

int employee_printList(LinkedList* empleados)
{
	int rtn = -1;
	int len;
	int i;
	Employee* aux = NULL;

	if(empleados!=NULL)
	{
		len = ll_len(empleados);

		if(len>0)
		{
			printf("ID\tNOMBRE\t\tHORAS\tSUELDO\n");

			for(i=0; i<len ;i++)
			{
				aux = (Employee*) ll_get(empleados,i);

				if(aux != NULL)
				{
					employee_printOneEmployee(aux);
					rtn=0;
				}
			}
		}
	}

	return rtn;
}

int employee_findID(LinkedList* empleados, int id)
{
	int i;
	int len;
	int index;
	Employee* auxiliar;

	if(empleados!=NULL)
	{
		len = ll_len(empleados);

		if(len>0)
		{
			for(i=0; i<len ;i++)
			{
				auxiliar = (Employee*)ll_get(empleados,i);
				if(auxiliar->id==id)
				{
					index=i;
					break;
				}
			}
		}
	}

	return index;
}


int employee_remove(LinkedList* empleados)
{
	int rtn = -1;
	int id;
	int index = -1;
	char respuesta[4];
	Employee* aux = NULL;

	if(empleados!=NULL)
	{
		employee_printList(empleados);
		utn_getInt(&id,1,5000,2,"Ingrese el ID para dar de baja: \n","Error, ID invalido\n");
		index = employee_findID(empleados,id);

		if(index!=-1)
		{
			aux = ll_get(empleados,index);
			employee_printOneEmployee(aux);
			utn_getString(respuesta,4,2,"\n¿Esta seguro que desea eliminar este empleado?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n");

			if(!(stricmp(respuesta,"si")))
			{
				ll_remove(empleados,index);
				printf("Baja realizada con exito\n");
			}
			else
			{
				printf("Baja cancelada\n");
			}
		}
		else
		{
			printf("No se pudo encontrar el ID\n");
		}
	}

	return rtn;
}

int employee_modify(LinkedList* empleados)
{
	int rtn = -1;
	int id;
	int index = -1;
	char respuesta[4];
	char confirmar[4];
	Employee* aux;
	Employee auxiliar;
	strcpy(confirmar,"no");

	if(empleados!=NULL)
	{
		employee_printList(empleados);
		utn_getInt(&id,1,5000,3,"Ingrese el ID para modificar\n","Error, ID invalido\n");
		index = employee_findID(empleados,id);

		if(index!=-1)
		{
			aux = (Employee*) ll_get(empleados,index);
			auxiliar=*aux;
			employee_printOneEmployee(&auxiliar);
			utn_getString(respuesta,4,3,"\n¿Esta seguro que desea editar este empleado?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n");

			if(!(stricmp(respuesta,"si")))
			{
				do
				{
					switch(employee_menuModify())
					{
						case 0:
							utn_getString(confirmar,4,3,"\n¿Esta seguro que desea salir?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n");
							break;
						case 1:
							employeeNombre(empleados,index,auxiliar);
							break;
						case 2:
							employeeHoras(empleados,index,auxiliar);
							break;
						case 3:
							employeeSueldo(empleados,index,auxiliar);
							break;
					}
				}while(stricmp(confirmar,"si"));
				printf("Modificacion realizada con exito\n");
			}
			else
			{
				printf("Modificacion cancelada\n");
			}
		}
		else
		{
			printf("No se pudo encontrar el ID\n");
		}
	}
	else
	{
		printf("Error. Imposible realizar una modificacion\n");
	}

	return rtn;
}

int employeeNombre(LinkedList* empleados, int index, Employee auxiliar)
{
	int rtn = -1;
	char auxNombre[128];
	int opciones;

	if(empleados!=NULL && index!=-1)
	{
		printf("\t****MODIFICAR NOMBRE****\t\n");
		utn_getString(auxNombre,128,3,"Ingrese el nuevo nombre\n","Error, nombre invalido\n");
		SizeString(auxNombre);

		strcpy(auxiliar.nombre,auxNombre);
		employee_printOneEmployee(&auxiliar);

		utn_getInt(&opciones,0,1,3,"\n¿Esta seguro que desea modificarlo? [1/0]\n","\nRespuesta invalida, ingrese [1/0]\n");
		if(opciones)
		{
			employee_modifyNombre(empleados,index,auxNombre);
			rtn=0;
		}
		else
		{
			printf("Modificacion cancelada");
		}
	}

	return rtn;
}

int employeeHoras(LinkedList* empleados, int index, Employee auxiliar)
{
	int rtn = -1;
	int auxHoras;
	int opciones;

	if(empleados!=NULL && index!=-1)
	{
		puts("\tMODIFICACION HORAS\t\n");
		utn_getInt(&auxHoras,1,500,3,"Ingrese la nueva cantidad de horas\n","Error, cantidad invalida\n");
		auxiliar.horasTrabajadas=auxHoras;
		employee_getHorasTrabajadas(&auxiliar,&auxHoras);
		employee_printOneEmployee(&auxiliar);
		utn_getInt(&opciones,0,1,3,"\n¿Esta seguro que desea modificarlo? (1 o 0)\n","\nRespuesta invalida, ingrese [1/0]\n");
		if(opciones)
		{
			employee_modifyHorasTrabajadas(empleados,index,auxHoras);
			rtn=0;
		}
		else
		{
			printf("Modificacion cancelada");
		}
	}
	return rtn;
}

int employeeSueldo(LinkedList* empleados, int index, Employee auxiliar)
{
	int rtn = -1;
	int auxSueldo;
	int opciones;

	if(empleados!=NULL && index!=-1)
	{
		puts("\tMODIFICACION SUELDO\t\n");
		utn_getInt(&auxSueldo,1000,500000,3,"Ingrese el nuevo sueldo \n","Error, cantidad invalida\n");
		auxiliar.sueldo=auxSueldo;
		employee_printOneEmployee(&auxiliar);
		utn_getInt(&opciones,0,1,3,"\n¿Esta seguro que desea modificarlo? (1/0)\n","\nRespuesta invalida, ingrese [1/0]\n");
		if(opciones)
		{
			employee_modifySueldo(empleados,index,auxSueldo);
			rtn=0;
		}
		else
		{
			puts("Modificacion cancelada");
		}
	}
	return rtn;
}



//VALIDACIONES

int employeChar(Employee* this, char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
	int rtn = -1;

	if(this!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
	{
		if((!(employee_setId(this,atoi(idStr))) &&
		!(employee_setNombre(this,nombreStr)) &&
		!(employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr))) &&
		!(employee_setSueldo(this,atoi(sueldoStr)))))
		{
			rtn=0;
		}
	}

	return rtn;
}

int employeInt(Employee* this, int id, char* nombre, int horasTrabajadas, int sueldo)
{
	int rtn = -1;

	if(this!=NULL && id>0 && nombre!=NULL && horasTrabajadas>0 && sueldo>0)
	{
		if((!(employee_setId(this,id)) &&
		!(employee_setNombre(this,nombre)) &&
		!(employee_setHorasTrabajadas(this,horasTrabajadas)) &&
		!(employee_setSueldo(this,sueldo))))
		{
			rtn=0;
		}
	}

	return rtn;
}


//SETERS



int employee_setId(Employee* this, int id)
{
	int aux = -1;

	if(this!=NULL && id>0)
	{
		this->id = id;
		aux=0;
	}

	return aux;
}

int employee_setNombre(Employee* this, char* nombre)
{
	int aux = -1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		aux=0;
	}

	return aux;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
	int aux = -1;

	if(this!=NULL && horasTrabajadas>0)
	{
		this->horasTrabajadas = horasTrabajadas;
		aux=0;
	}

	return aux;
}

int employee_setSueldo(Employee* this, int sueldo)
{
	int aux = -1;

	if(this!=NULL && sueldo>0)
	{
		this->sueldo = sueldo;
		aux=0;
	}

	return aux;
}
//
int employee_getId(Employee* this, int* id)
{
	int rtn = -1;

	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		rtn=0;
	}

	return rtn;
}
int employee_getNombre(Employee* this, char* nombre)
{
	int rtn = -1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		rtn=0;
	}

	return rtn;
}
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
	int rtn = -1;

	if(this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		rtn=0;
	}

	return rtn;
}
int employee_getSueldo(Employee* this, int* sueldo)
{
	int rtn = -1;

	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo = this->sueldo;
		rtn=0;
	}

	return rtn;
}

int employeeGets(Employee* this, int* id, char* nombre, int* horasTrabajadas, int* sueldo)
{
	int rtn = -1;

	if(this!=NULL && id!=NULL && nombre!=NULL && horasTrabajadas!=NULL && sueldo!=NULL)
	{
		if((!(employee_getId(this,id)) &&
		!(employee_getNombre(this,nombre)) &&
		!(employee_getHorasTrabajadas(this,horasTrabajadas)) &&
		!(employee_getSueldo(this,sueldo))))
		{
			rtn=0;
		}
	}

	return rtn;
}



int ObtenerMayorId (LinkedList* empleados)
{
	int mayorId=0;
	int id;
	int len;
	int i;
	Employee* aux;

	if(empleados!=NULL)
	{
		len = ll_len(empleados);

		if(len>0)
		{
			for(i=0;i<len;i++)
			{
				aux = (Employee*)ll_get(empleados,i);
				employee_getId(aux,&id);

				if(i==0 || (mayorId<id))
				{
					mayorId=id;
				}
			}
		}
	}

	return mayorId;
}



int employee_menuModify()
{
	int opcion;

	printf("\n\t>-MENU MODIFICACIONES-<\t\n");
	printf("1. Modificar nombre\n");
	printf("2. Modificar horas trabajadas\n");
	printf("3. Modificar sueldo\n");
	printf("0. Salir\n");

	utn_getInt(&opcion,1,10,3,"\nIngrese una opcion: ","\nError, opcion invalida: ");

	return opcion;
}

int employee_menuOrden()
{
	int opcion;

	printf("\n\t>-MENU ORDEN-<\t\n");
	printf("1. Ordenar por ID\n");
	printf("2. Ordenar por nombre\n");
	printf("3. Ordenar por horas trabajadas\n");
	printf("4. Ordenar por sueldo\n");
	printf("5. Mostrar lista ordenada\n");
	printf("0. Salir\n");

	utn_getInt(&opcion,1,10,3,"\nIngrese una opcion: ","\nError, opcion invalida: ");

	return opcion;
}

int employee_subMenuOrden()
{
	int opcion;

	printf("\n\t>-CRITERIO DE ORDEN-<\t\n");
	printf("0. Descendente\n");
	printf("1. Ascendente\n");

	utn_getInt(&opcion,1,10,3,"\nIngrese una opcion: ","\nError, opcion invalida: ");

	return opcion;
}

int employee_compareById(void* empleado1, void* empleado2)
{
	int resultado = 0;//si son iguales
	Employee* emp1 = NULL;
	Employee* emp2 = NULL;
	int id1;
	int id2;

	if(empleado1!=NULL && empleado2!=NULL)
	{
		emp1 = (Employee*) empleado1;
		emp2 = (Employee*) empleado2;

		if((!employee_getId(emp1,&id1)) && (!employee_getId(emp2,&id2)))
		{
			if(id1 > id2)//mayores
			{
				resultado = 1;
			}
			else
			{
				if(id1 < id2)//menores
				{
					resultado = -1;
				}
			}
		}
	}

	return resultado;
}
int employee_compareByNombre(void* empleado1, void* empleado2)
{
	int resultado = -1;
	Employee* emp1 = NULL;
	Employee* emp2 = NULL;
	char nombre1[128];
	char nombre2[128];

	if(empleado1!=NULL && empleado2!=NULL)
	{
		emp1 = (Employee*) empleado1;
		emp2 = (Employee*) empleado2;

		if((!employee_getNombre(emp1,nombre1)) && (!employee_getNombre(emp2,nombre2)))
		{
			resultado = strcmp(nombre1,nombre2);
		}
	}

	return resultado;
}

int employee_compareByHorasTrabajadas(void* empleado1, void* empleado2)
{
	int resultado = 0;//si son iguales
	Employee* emp1;
	Employee* emp2;
	int horas1;
	int horas2;

	if(empleado1!=NULL && empleado2!=NULL)
	{
		emp1 = (Employee*) empleado1;
		emp2 = (Employee*) empleado2;

		if((!employee_getHorasTrabajadas(emp1,&horas1)) && (!employee_getHorasTrabajadas(emp2,&horas2)))//mayores
		{
			if(horas1 > horas2)//menores
			{
				resultado = 1;
			}
			else
			{
				if(horas1 < horas2)//menores
				{
					resultado = -1;
				}
			}
		}
	}

	return resultado;
}

int employee_compareBySueldo(void* empleado1, void* empleado2)
{
	int resultado = 0;//si son iguales
	Employee* emp1 = NULL;
	Employee* emp2 = NULL;
	int sueldo1;
	int sueldo2;

	if(empleado1!=NULL && empleado2!=NULL)
	{
		emp1 = (Employee*) empleado1;
		emp2 = (Employee*) empleado2;

		if((!employee_getSueldo(emp1,&sueldo1)) && (!employee_getSueldo(emp2,&sueldo2)))
		{
			if(sueldo1 > sueldo2)//mayores
			{
				resultado=1;
			}
			else
			{
				if(sueldo1 < sueldo2)//menores
				{
					resultado=-1;
				}
			}
		}
	}

	return resultado;
}


int employee_modifyNombre(LinkedList* empleados, int index, char* auxNombre)
{
	int rtn = -1;
	Employee* aux;

	if(empleados!=NULL && index>=0 && auxNombre!=NULL)
	{
		aux = (Employee*) ll_get(empleados,index);
		SizeString(auxNombre);

		if(aux!=NULL)
		{
			if(!employee_setNombre(aux,auxNombre))
			{
				printf("Se cargo correctamente el nuevo nombre\n");
			}
			else
			{
				printf("No se pudo modificar el nombre\n");
			}
			rtn=0;
		}
	}

	return rtn;
}
int employee_modifyHorasTrabajadas(LinkedList* empleados, int index, int auxHoras)
{
	int rtn = -1;
	Employee* aux;

	if(empleados!=NULL && index>=0 && auxHoras>0)
	{

		aux = (Employee*) ll_get(empleados,index);

		if(aux!=NULL)
		{
			if(!employee_setHorasTrabajadas(aux,auxHoras))
			{
				printf("Se cargo correctamente la nueva cantidad de horas\n");
			}
			else
			{
				printf("No se pudo modificar las horas\n");
			}
			rtn=0;
		}
	}
	return rtn;
}
int employee_modifySueldo(LinkedList* empleados, int index, int auxSueldo)
{
	int rtn = -1;
	Employee* aux;

	if(empleados!=NULL && index>=0 && auxSueldo>=1000)
	{

		aux = (Employee*) ll_get(empleados,index);

		if(aux!=NULL)
		{
			if(!employee_setSueldo(aux,auxSueldo))
			{
				printf("Se cargo correctamente el nuevo sueldo\n");
			}
			else
			{
				printf("No se pudo modificar el sueldo\n");
			}
			rtn=0;
		}
	}
    return rtn;
}
