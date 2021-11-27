#include "Sector.h"
#include "input.h"

void HardcodeoSector(eSector listaSectores[])
{
	int auxId[SECTOR]={1,2,3};
	char auxDescripcion[SECTOR][25]={"chef","limpiaplatos","cocinero"};
	int i;

	for(i=0;i<SECTOR;i++)
	{
		listaSectores[i].id=auxId[i];
		strcpy(listaSectores[i].descripcion,auxDescripcion[i]);
	}
}

void MostrarSector(eSector unSector)
{
	printf("%d. %s \n",unSector.id,
				       unSector.descripcion);
}

void MostrarListaSectores(eSector sectores[], int tam)
{
	int i;
	printf("\n> LISTA DE SECTORES: \n");
	for(i=0; i<tam; i++)
	{
		MostrarSector(sectores[i]);
	}
}

int GetDescripcionS(eSector sectores[], int tam, int buscar,char descripcion[])
{
	int isOk=-1;
	int i;

	if(sectores != NULL && tam>0 && descripcion != NULL)
	{
		for(i=0; i<tam ;i++)
		{
			if(sectores[i].id==buscar)
			{
				strcpy(descripcion,sectores[i].descripcion);
				isOk=0;
				break;
			}
		}
	}

	return isOk;
}
