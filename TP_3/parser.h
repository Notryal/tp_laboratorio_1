/*
 * parser.h
 *
 *  Created on: 7 nov. 2021
 *      Author: Usuario
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_IdFromText(FILE* pFile , LinkedList* pArrayListEmployee, int* id);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
