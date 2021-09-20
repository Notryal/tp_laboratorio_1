#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include "operaciones.h"
/***
 * @fn int suma(int, int)
 * @brief Recibe dos numeros y los suma
 *
 * @pre
 * @post
 * @param A 1er operando
 * @param B 2do operando
 * @return resultado de la Suma
 */

int suma(int numeroA, int numeroB){
	int resultadoSuma;

	resultadoSuma= numeroA+numeroB;

	return resultadoSuma;
}

/***
 * @fn int resta(int, int)
 * @brief Recibe dos numeros y los resta
 *
 * @pre
 * @post
 * @param A 1er operando
 * @param B 2do operando
 * @return resultado de la Resta
 */

int resta(int numeroA, int numeroB){
	int resultadoResta;

	resultadoResta= numeroA-numeroB;

	return resultadoResta;
}
/***
 * @fn int division(int, int)
 * @brief Recibe dos numeros y los divide, verifica que el divisor sea distinto de 0
 *
 * @pre
 * @post
 * @param A 1er operando
 * @param B 2do operando
 * @return resultado de la division
 */

int division(int numeroA, int numeroB){
	int resultadoDivision;

	if(numeroB!=0){
		resultadoDivision= numeroA/numeroB;
	}else{
		resultadoDivision=printf("Es imposible entre 0 o 0 como divisor");
	}
	return resultadoDivision;
}

/***
 * @fn int multiplicacion(int, int)
 * @brief Recibe dos numeros y los multiplica
 *
 * @pre
 * @post
 * @param A 1er operando
 * @param B 2do operando
 * @return resultado de la multiplicacion
 */

int multiplicacion(int numeroA, int numeroB){
	int resultadoMultiplicacion;

	resultadoMultiplicacion= numeroA*numeroB;
	return resultadoMultiplicacion;
}
/***
 * @fn long int factorial(int)
 * @brief recibe un numero y realiza su factorial
 *
 * @pre
 * @post
 * @param A o B 1er operando

 * @return resultado de la factorial
 */

long int factorial(int numero){
	long int resultadoFactorial=1;
	int i;

	if(numero==0){
		resultadoFactorial=1;
	}else if(numero>0){
			for (i = numero; i > 0; i--)
				{
				resultadoFactorial *= i;
				}
	}else{
		printf("Incorrecto, el numero ingresado es un numero negativo");
	}

	return resultadoFactorial;
}
