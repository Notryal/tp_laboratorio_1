#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

#include "menu.h"



int suma(int numeroA, int numeroB){
	int resultadoSuma;
	resultadoSuma= numeroA+numeroB;

	return resultadoSuma;
}



int resta(int numeroA, int numeroB){
	int resultadoResta;

	resultadoResta= numeroA-numeroB;

	return resultadoResta;
}


int division(int numeroA, int numeroB){
	int resultadoDivision;

	if(numeroB!=0){
		resultadoDivision= numeroA/numeroB;
	}else{
		resultadoDivision=printf("Es imposible entre 0 o 0 como divisor");
	}
	return resultadoDivision;
}



int multiplicacion(int numeroA, int numeroB){
	int resultadoMultiplicacion;

	resultadoMultiplicacion= numeroA*numeroB;
	return resultadoMultiplicacion;
}


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
