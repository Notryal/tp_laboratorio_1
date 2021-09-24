#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "operaciones.h"
#include "menu.h"
#include "input.h"

float pedirFlotante(char* mensaje){
    float numero;
    printf(mensaje);
    fflush(stdin);
    scanf("%f", &numero);
    return numero;
}

int pedirEntero(char* mensaje){
    int numero;
    printf(mensaje);
    fflush(stdin);
    scanf("%d", &numero);
    return numero;
}

int esEntero(float numero){
    int integral = numero;
    int esEntero = 0;
    if (numero - integral == 0){
        esEntero = 1;
    }
    return esEntero;
}

