#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
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

	    do
	    {
	    	printf("\n*Bienvenido al menu* ");
	    	printf("\n Ingrese 0 para ingresar numeros A y B:");
			printf ("\nLas operaciones posibles son : \n");
			printf ("\n1) Calcular la suma (A+B)");
			printf ("\n2) Calcular la resta (A-B) ");
			printf ("\n3) Calcular la division (A/B) ");
			printf ("\n4) Calcular la multiplicacion (A*B) ");
			printf ("\n5) Calcular el factorial (A!) ");
			printf ("\n6) Calcular el factorial (B!) ");
			printf ("\n7) Salir del menu \n");
	    	scanf("%d", &opcion);

			switch(opcion)
				{
				case 0:
					printf("Ingresar 1er operando (A=x) : \n");
					scanf("%d", &numeroA);
					printf("Ingresar 2do operando (B=y) : \n");
					scanf("%d", &numeroB);
					printf("\nNumeros cargados A= %d || B= %d",numeroA, numeroB);
				break;
				case 1:
					resultadoSuma=suma(numeroA,numeroB);
					printf ("\n El resultado de %d+%d es: %d",numeroA, numeroB,resultadoSuma);
					break;
				case 2:
					resultadoResta=resta(numeroA,numeroB);
					printf("\n El resultado de %d-%d es: %d",numeroA, numeroB,resultadoResta);
					break;
				case 3:
					resultadoDivision=division(numeroA,numeroB);
					printf("\n El resultado de %d/%d es: %d",numeroA, numeroB,resultadoDivision);
					break;
				case 4:
					resultadoMultiplicacion=multiplicacion(numeroA,numeroB);
					printf("\n El resultado de %d*%d es: %d",numeroA, numeroB,resultadoMultiplicacion);
					break;
				case 5:
					resultadoFactorialA=factorial(numeroA);
					printf("\n El factorial de %d! es: %ld",numeroA, resultadoFactorialA);
					break;
				case 6:
					resultadoFactorialB=factorial(numeroB);
					printf("\n El factorial de %d! es: %ld",numeroB, resultadoFactorialB);
					break;
				case 7:
					printf("\n Hasta luego!");
					break;
				default:
					printf("Opcion invalida");
				}
		    } while (opcion != 7);
	    }










