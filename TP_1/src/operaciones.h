#ifndef OPERACIONES_H_
#define OPERACIONES_H_

/***
 * @fn int suma(int, int)
 * @brief Recibe dos numeros y los suma
 *
 * @param A 1er operando
 * @param B 2do operando
 * @return resultado de la Suma
 */
int suma(int numeroA, int numeroB);

/***
 * @fn int resta(int, int)
 * @brief Recibe dos numeros y los resta
 *
 * @param A 1er operando
 * @param B 2do operando
 * @return resultado de la Resta
 */
int resta(int numeroA, int numeroB);

/***
 * @fn int division(int, int)
 * @brief Recibe dos numeros y los divide, verifica que el divisor sea distinto de 0
 *
 * @param A 1er operando
 * @param B 2do operando
 * @return resultado de la division
 */
int division(int numeroA, int numeroB);

/***
 * @fn int multiplicacion(int, int)
 * @brief Recibe dos numeros y los multiplica
 *
 * @param A 1er operando
 * @param B 2do operando
 * @return resultado de la multiplicacion
 */
int multiplicacion(int numeroA, int numeroB);

/***
 * @fn long int factorial(int)
 * @brief recibe un numero y realiza su factorial, se fija si el numero es negativo o 0
 *
 * @param Numero es un operando
 * @return resultado de la factorial, en caso de que sea posible o no
 */
long int factorial(int numero);

#endif
