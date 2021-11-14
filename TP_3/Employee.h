#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "input.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr); //agrego sueldoStr
void employee_delete(Employee* this); //libero memoria  //deallocates the block of memory pointed at by ptr.

int employee_add(LinkedList* listaEmpleados, int* id);
int employee_remove(LinkedList* listaEmpleados);
int employee_modify(LinkedList* listaEmpleados);

int employeInt(Employee* this, int id, char* nombre, int horasTrabajadas, int sueldo);
int employeChar(Employee* this, char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);

int employeeGets(Employee* this, int* id, char* nombre, int* horasTrabajadas, int* sueldo);

int employee_setId(Employee* this,int id);//paso id y guardo
int employee_getId(Employee* this,int* id);//pregunta id
int employee_findID(LinkedList* listaEmpleados, int id);
int employee_printOneEmployee(Employee* this);
int employee_printList(LinkedList* listaEmpleados);

int employee_setId(Employee* this, int id);
int employee_getId(Employee* this, int* id);
int ObtenerMayorId(LinkedList* listaEmpleados);
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas);
int employee_caseHoras(LinkedList* listaEmpleados, int index, Employee auxiliar);
int employee_modifyHorasTrabajadas(LinkedList* listaEmpleados, int index, int auxHoras);
int employee_compareByHorasTrabajadas(void* empleado1, void* empleado2);

int employee_compareById(void* empleado1, void* empleado2);
int employee_setNombre(Employee* this, char* nombre);
int employee_getNombre(Employee* this, char* nombre);
int employee_caseNombre(LinkedList* listaEmpleados, int index, Employee auxiliar);
int employee_modifyNombre(LinkedList* listaEmpleados, int index, char* auxNombre);
int employee_compareByNombre(void* empleado1, void* empleado2);
int employee_setSueldo(Employee* this, int sueldo);
int employee_getSueldo(Employee* this, int* sueldo);
int employee_caseSueldo(LinkedList* listaEmpleados, int index, Employee auxiliar);
int employee_modifySueldo(LinkedList* listaEmpleados, int index, int auxSueldo);
int employee_compareBySueldo(void* empleado1, void* empleado2);

int employee_subMenuOrden();
int employee_menuOrden();
int employee_menuModify();







#endif // employee_H_INCLUDED
