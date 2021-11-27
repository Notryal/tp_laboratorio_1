#include "Funciones.h"
#include "Employees.h"
#include "Sector.h"
#include "input.h"

int main(void) {
	setbuf(stdout,NULL);
	char confirmar[4];
	int cantidad;
	int flag;
	int opcion;
	int i;
	eEmpleado unEmpleado[TAM];
	eSector unSector[SECTOR];
	int auxId=0;
	int index;
	char auxNombre[51];
	char auxApellido[51];
	float auxSalario;
	int auxIdSector;

	strcpy(confirmar,"no");

	IniciarEmpleados(unEmpleado,TAM);
	HardcodeoSector(unSector);

	do
	{
		switch(Menu())
		{
			case 0:

				utn_getString("\nEstas seguro que queres salir? si o no\n","\nRespuesta invalida, ingrese si o no\n",4,2,confirmar);
				puts("Hasta luego!");
				break;
			case 1:
				i=0;
				printf("\t\t>ALTAS<\t\t\n");
				utn_getInt("Cuantos empleados desea dar de alta?\n","Error, cantidad invalida\n",1,1000,2,&cantidad);
				do
				{
					if(!(PedirData(unEmpleado,TAM,unSector,SECTOR,&auxId,auxNombre,auxApellido,&auxSalario,&auxIdSector,&index)) &&
					!(AltaEmpleado(unEmpleado,TAM,unSector,SECTOR,auxId,auxNombre,auxApellido,auxSalario,auxIdSector,index)))
					{
						flag=1;
					}
					else
					{
						flag=0;
					}
					 	 i++;
				}while(cantidad!=i);

				if(flag==1)
				{
					puts("Se han dado de alta con exito\n");
				}
				else
				{
					puts("Hubo un error o la lista esta llena en el momento\n");
				}
				break;
			case 2:
				puts("\t\t>MODIFICAR<\t\t\n");
				if(flag==1)
				{
					ModificarEmpleado(unEmpleado,TAM,unSector,SECTOR,auxId,auxNombre,auxApellido,auxSalario,auxIdSector,index);
				}
				else
				{
					puts("Error, no se han dado de alta\n");
				}
				break;
			case 3:
				i=0;
				puts("\t\t>BAJAS<\t\t\n");
				if(flag==1)
				{
					utn_getInt("Cuantos empleados desea dar de baja?\n""","Error, cantidad invalida\n",1,1000,2,&cantidad);
					do
					{
						if(BajaEmpleado(unEmpleado,TAM,unSector,SECTOR,&auxId))
						{
							puts("Ningun cambio realizado\n");
						}
						i++;
					}while(cantidad!=i);
				}
				else
				{
					puts("Error, no se han dado de alta empleados\n");
				}
				break;
			case 4:
				printf("\t\t>INFORMES<<\t\t\n");
				if(flag==1)
				{
					MostrarInformes(unEmpleado,TAM,unSector,SECTOR);
				}
				else
				{
					puts("Error, no se han dado de alta empleados\n");
				}
				break;
		}
	}while(opcion != 0);


	return EXIT_SUCCESS;
}
