#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "operaciones.h"
#include "input.h"


void menuPrincipal(){
	int opcion;
	int numeroA=0;
	int numeroB=0;
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
	    	printf("\n*Bienvenido al menu*");
	    	printf("\n1- Ingrese 1er Operando A=x");
			printf("\n2- Ingrese 2do Operando B=y");
			printf("\n3- Calcular todas las operaciones");
			printf("\n4- Informar resultados");
			printf("\n5- Salir del menu");
			opcion =pedirEntero("\nElija su opcion : ");

			switch(opcion)
				{
				case 1:
					numeroA=pedirEntero("\nIngresar 1er operando (A=x) : ");
					printf("\nNumero cargado A= %d",numeroA);
				    flagA =1;
				break;
				case 2:
					numeroB=pedirEntero("\nIngresar 2do operando (B=y) : ");
				    flagB =1;
					printf("\nNumero cargado B= %d", numeroB);
				break;
				case 3:
					printf("\nNumeros cargados A= %d || B= %d",numeroA, numeroB);
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
						printf("\nEl resultado de %d+%d es: %d",numeroA, numeroB,resultadoSuma);
						printf("\nEl resultado de %d-%d es: %d",numeroA, numeroB,resultadoResta);

						if(numeroB!=0){
							printf("\nEl resultado de %d/%d es: %f",numeroA, numeroB,resultadoDivision);
						}else{
							printf("\nEl resultado de %d/%d no se puede hacer. La division por cero no se puede realizar.",numeroA, numeroB);
						}

						printf("\nEl resultado de %d*%d es: %d",numeroA, numeroB,resultadoMultiplicacion);

						if(numeroA<0){
							printf("\nEl factorial de %d! no se puede hacer. El numero ingresado es un numero negativo",numeroA);
						}else{
							printf("\nEl factorial de %d! es: %ld",numeroA, resultadoFactorialA);
						}

						if(numeroB<0){
							printf("\nEl factorial de %d! no se puede hacer el numero ingresado es un numero negativo",numeroB);
						}else{
							printf("\nEl factorial de %d! es: %ld",numeroB, resultadoFactorialB);
						}
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










