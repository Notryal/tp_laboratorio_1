#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "operaciones.h"
#include "menu.h"
#include "input.h"


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


float division(int numeroA, int numeroB){
	float resultadoDivision;

	if(numeroB!=0){
		resultadoDivision= (float)numeroA/numeroB;
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
	}else if(numero<0){
			for (i = numero; i > 0; i--)
				{
				resultadoFactorial *= i;
				}
	}

	return resultadoFactorial;
}
