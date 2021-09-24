#include <stdio.h>
#include <stdlib.h>

#include "input.h"

int PedirEntero(char mensaje[])
{
    int numero;

    printf("%s",mensaje);
	scanf("%d",&numero );

	return numero;
}

float PedirFlotante(char mensaje[])
{
    float numero;

    printf("%s",mensaje);
	scanf("%f",&numero );

	return numero;
}
void GetString(char mensaje[],char cadena[],int tam)
{
    char auxiliar[tam];
    printf("%s", mensaje);
    __fpurge(stdin);
    scanf("%s", auxiliar);
    scanf("%[^\n]");
    strcpy(cadena, auxiliar);
}

