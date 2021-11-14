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
    int option = 0;
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






            	break;
            case 4:

            	break;
            case 5:

            	break;
            case 6:

            	break;
            case 7:

            	break;
            case 8:

            	break;
            case 9:

            	break;
            case 10:

            	break;
        }

    }while(option != 10);
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
