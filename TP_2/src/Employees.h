#ifndef EMPLOYEES_H_
#define EMPLOYEES_H_

#define TAM 1000
#define VACIO 0
#define OCUPADO 1

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float salario;
	int idSector;
	int isEmpty;
}eEmpleado;
/**
 * @fn int IniciarEmpleados(eEmpleado[], int)
 * @brief inicializa mi array de empleados en VACIO
 *
 * @param Recibe el array de empleados
 * @param recibe el tama�o
 * @return devuelve 0 si salio todo bien, devuelve -1 si salio todo mal
 */
int IniciarEmpleados(eEmpleado[],int);
/**
 * @fn int BuscarLibre(eEmpleado[], int)
 * @brief recorre mi array de empleados y busca en que posicion se encuentra isEmpty VACIO
 *
 * @param Recibe el array de empleados
 * @param recibe el tama�o
 * @return devuelve -1 si no hay espacio libre o devuelve el valor de la posicion que se encuentra libre
 */
int BuscarLibre(eEmpleado[],int);
/**
 * @fn int BuscarEmpleadosPorId(eEmpleado[], int, int*)
 * @brief recibe un numero id
 *
 * @param recibe el array de empleados
 * @param recibe el tama�o
 * @param recibe un id por puntero
 * @return devuelve -1 si no hay espacio libre o devuelve el valor de la posicion que se encuentra ese empleado
 */
int BuscarEmpleadosPorId(eEmpleado[], int, int*);
/**
 * @fn int OrdenarEmpleados(eEmpleado[], int, int)
 * @brief
 *
 * @param lista recibe un array de empleados
 * @param tam recibe el tama�o
 * @param orden recibe por puntero el valor para ordenar
 * @return devuelve 0 si salio todo bien, devuelve -1 si salio todo mal
 */
int OrdenarEmpleados(eEmpleado lista[], int tam, int orden);



#endif /* EMPLOYEES_H_ */
