#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "operaciones.h"

/***
 * @fn void menuPrincipal()
 * @brief Es el menu principal, muestra las opciones,
 * llama funciones en caso de realizar una operacion y muestra los resultados
 *
 * @pre
 * @post
 */

void menuPrincipal(){
	int opcion;
	int numeroA;
	int numeroB;
    int resultadoSuma;
    int resultadoResta;
    int resultadoDivision;
    int resultadoMultiplicacion;
    long int resultadoFactorialA;
    long int resultadoFactorialB;
    int flagA =0;
    int flagB =0;
	    do
	    {
	    	printf("\n");
	    	printf("\n*Bienvenido al menu*");
	    	printf("\n 1- Ingrese 1er Operando A=x");
			printf("\n 2- Ingrese 2do Operando B=y");
			printf("\n 3- Calcular todas las operaciones");
			printf("\n 4- Informar resultados");
			printf ("\n5- Salir del menu \n");
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
						printf("Por favor ingresar numeros A y B, presione la opcion 1")
					}else{
						resultadoSuma=suma(numeroA,numeroB);
						resultadoResta=resta(numeroA,numeroB);
						resultadoDivision=division(numeroA,numeroB);
						resultadoMultiplicacion=multiplicacion(numeroA,numeroB);
						resultadoFactorialA=factorial(numeroA);
						resultadoFactorialB=factorial(numeroB);
					}
					break;
				case 4:
					printf("\n El resultado de %d+%d es: %d",numeroA, numeroB,resultadoSuma);
					printf("\n El resultado de %d-%d es: %d",numeroA, numeroB,resultadoResta);
					printf("\n El resultado de %d/%d es: %d",numeroA, numeroB,resultadoDivision);
					printf("\n El resultado de %d*%d es: %d",numeroA, numeroB,resultadoMultiplicacion);
					printf("\n El factorial de %d! es: %ld",numeroA, resultadoFactorialA);
					printf("\n El factorial de %d! es: %ld",numeroB, resultadoFactorialB);
					break;
				case 5:
					printf("\n Hasta luego!");
					break;
				default:
					printf("Opcion invalida");
				}
		    } while (opcion != 5);
	    }










