#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "operaciones.h"



void menuPrincipal(){
	int opcion;
	int numeroA;
	int  numeroB;
    int resultadoSuma;
    int resultadoResta;
    float resultadoDivision;
    int resultadoMultiplicacion;
    long int resultadoFactorialA;
    long int resultadoFactorialB;
    int flagA =0;
    int flagB =0;
    int flagC =0;
	    do
	    {
	    	printf("\n");
	    	printf("\n*Bienvenido al menu*");
	    	printf("\n1- Ingrese 1er Operando A=x");
			printf("\n2- Ingrese 2do Operando B=y");
			printf("\n3- Calcular todas las operaciones");
			printf("\n4- Informar resultados");
			printf("\n5- Salir del menu");
			printf("\nElija su opcion : ");
	    	scanf("%d", &opcion);

			switch(opcion)
				{
				case 1:
					printf("\nIngresar 1er operando (A=x) : ");
					scanf("%d", &numeroA);
					printf("\nNumeros cargados A= %d || B= %d",numeroA, numeroB);
				    flagA =1;
				break;
				case 2:
					printf("\nIngresar 2do operando (B=y) : ");
					scanf("%d", &numeroB);
				    flagB =1;
					printf("\nNumeros cargados A= %d || B= %d",numeroA, numeroB);
				break;
				case 3:
					if(flagA==0 && flagB==0){
						printf("Por favor ingresar numeros A y B, presione la opcion 1");
					}else{
						resultadoSuma=suma(numeroA,numeroB);
						resultadoResta=resta(numeroA,numeroB);
						resultadoDivision=division(numeroA,numeroB);
						resultadoMultiplicacion=multiplicacion(numeroA,numeroB);
						resultadoFactorialA=factorial(numeroA);
						resultadoFactorialB=factorial(numeroB);
						flagC=1;
					}
					break;
				case 4:
					if(flagC==0){
						printf("No hay ningun resultado por mostrar, ingrese 3 primero y luego 4");
					}else{
						printf("\n El resultado de %d+%d es: %d",numeroA, numeroB,resultadoSuma);
						printf("\n El resultado de %d-%d es: %d",numeroA, numeroB,resultadoResta);
						printf("\n El resultado de %d/%d es: %.2f",numeroA, numeroB,resultadoDivision);
						printf("\n El resultado de %d*%d es: %d",numeroA, numeroB,resultadoMultiplicacion);
						printf("\n El factorial de %d! es: %ld",numeroA, resultadoFactorialA);
						printf("\n El factorial de %d! es: %ld",numeroB, resultadoFactorialB);
					}
					break;
				case 5:
					printf("\n Hasta luego!");
					break;
				default:
					printf("Opcion invalida");
				}
		    } while (opcion != 5);
	    }










