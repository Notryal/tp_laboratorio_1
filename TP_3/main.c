#include "input.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int menu();

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).//memoria a disco guardo los cambios realizados
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout,NULL);
	char confirmar[4];
	int opcion = 0;
	int flagSaveTxt = 0;
	int flagSaveBin = 0;
	int id=1000;

    int flagA = 0;
    int rtnAux;
    LinkedList* empleados = ll_newLinkedList();
    do{
        switch(menu())
        {
            case 1:
//verificar
            	if(ll_isEmpty(empleados) && flagA==0){

            		rtnAux = controller_loadFromText("data.csv",empleados);

            		if(rtnAux){
            			puts("Se cargo con exito\n");
            			flagA=1;
            		} else if(rtnAux ==0){
            			puts("Error, no se cargo nada\n");
            		}else{
            			puts("Error, el path o la lista no tienen nada\n");
            		}

            	}else{

            		puts("No se puede cargar la lista dos veces");
            	}

                break;
            case 2:

            	if(ll_isEmpty(empleados) && flagA==0){

            		rtnAux = controller_loadFromBinary("data.csv",empleados);

            		if(rtnAux){
            			puts("Se cargo con exito\n");
            			flagA=1;
            		} else if(rtnAux ==0){
            			puts("Error, no se cargo nada\n");
            		}else{
            			puts("Error, el path o la lista no tienen nada\n");
            		}

            	}else{

            		puts("No se puede cargar la lista dos veces");
            	}


            	break;
            case 3:
				if(!controller_addEmployee(empleados,&id))
				{
					controller_saveAsTextID("id.csv",empleados,id);
				}
            	break;
			case 4:
				if(!ll_isEmpty(empleados))
				{
					controller_editEmployee(empleados);
				}
				else
				{
					printf("No hay empleados para modificar");
				}
				break;
			case 5:
				if(!ll_isEmpty(empleados))
				{
					controller_removeEmployee(empleados);
				}
				else
				{
					printf("No hay empleados para dar de baja");
				}
				break;
			case 6:
				if(!ll_isEmpty(empleados))
				{
					controller_ListEmployee(empleados);
				}
				else
				{
					printf("No hay empleados para mostrar");
				}
				break;
			case 7:
				if(!ll_isEmpty(empleados))
				{
					controller_sortEmployee(empleados);
				}
				else
				{
					printf("No hay empleados para mostrar");
				}
				break;
			case 8:
				if(!ll_isEmpty(empleados))
				{
					controller_saveAsText("data2.csv",empleados);
					controller_saveAsTextID("id.csv",empleados,id);
					flagSaveTxt=1;
				}
				else
				{
					printf("No hay empleados para guardar");
				}
				break;
			case 9:
				if(!ll_isEmpty(empleados))
				{
					controller_saveAsBinary("data.bin",empleados);
					controller_saveAsTextID("id.csv",empleados,id);
					flagSaveBin=1;
				}
				else
				{
					printf("No hay empleados para guardar");
				}
				break;
			case 10:
				if((flagSaveTxt==0) && (flagSaveBin==0))
				{
					utn_getString(confirmar,4,3,"\nEsta seguro que desea salir sin guardar?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n");
					if(stricmp(confirmar,"si"))
					{
						utn_getInt(&opcion,1,2,3,"\n1. Guardar modo texto\n2. Guardar modo binario\n","\nRespuesta invalida, ingrese [1/2]\n");
						if(opcion==1)
						{
							controller_saveAsText("data2.csv",empleados);
							strcpy(confirmar,"si");
						}
						else
						{
							controller_saveAsBinary("data.bin",empleados);
							strcpy(confirmar,"si");
						}
					}
				}
				else
				{
					strcpy(confirmar,"si");
				}

				break;
		}
	}while(stricmp(confirmar,"si"));
	printf("Gracias por utilizar nuestro servicio");
    return 0;
}


int menu()
{
	int opcion;

	puts("\n\tMENU\t\n");
	puts("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
	puts("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
	puts("3. Alta de empleado\n");
	puts("4. Modificar datos de empleado\n");
	puts("5. Baja de empleado\n");
	puts("6. Listar empleados\n");
	puts("7. Ordenar empleados\n");
	puts("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
	puts("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
	puts("10. Salir\n");

	utn_getInt(&opcion,1,10,3,"\nIngrese una opcion: ","\nError, opcion invalida: ");

	return opcion;
}
