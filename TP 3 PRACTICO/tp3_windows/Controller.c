#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int exito = 0;

	FILE* pArchivo;

	pArchivo = fopen(path, "r");

	if(pArchivo == NULL){

		printf("\nNo se pudo leer el archivo\n");
	}
	else{
		printf("\nSe pudo leer el archivo\n");
		parser_EmployeeFromText(pArchivo, pArrayListEmployee);

		fclose(pArchivo);
		exito = 1;
	}

    return exito;
}

int controller_SecondloadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int exito = 0;

	FILE* pArchivo;

	pArchivo = fopen(path, "r");

	if(pArchivo == NULL){

		printf("\nNo se pudo leer el archivo\n");
	}
	else{
		printf("\nSe pudo leer el archivo\n");
		parser_SecondEmployeeFromText(pArchivo, pArrayListEmployee);

		fclose(pArchivo);
		exito = 1;
	}

    return exito;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int exito = 0;

	FILE* pArchivo;

	pArchivo = fopen(path, "rb");

	if(pArchivo == NULL){

		printf("\nNo se pudo leer el archivo\n");
	}
	else{
		printf("\nSe pudo leer el archivo\n");
		//parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);

		fclose(pArchivo);
		exito = 1;
	}

	return exito;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* nuevoEmpleado;
	int exito = 0;
	int nuevoId;
	char nombre[128];
	int sueldo;
	int horasTrabajadas;

	nuevoId = ll_len(pArrayListEmployee);

	nuevoId = nuevoId + 1;

	printf("\n\tAlta Empleado\n\n");

	printf("El ID del nuevo Empleado es: %d", nuevoId);

	printf("\nIngrese nombre del Empleado: ");
	fflush(stdin);
	gets(nombre);
	while(strlen(nombre) > 128){
		printf("Invalido. Reingrese nombre del Empleado: ");
		gets(nombre);
		fflush(stdin);
	}

	printf("\nIngrese cantidad de Horas Trabajadas: ");
	fflush(stdin);
	scanf("%d", &horasTrabajadas);
	while(horasTrabajadas < 0 || horasTrabajadas > 1000){
		printf("Invalido. Reingrese cantidad de Horas Trabajadas: ");
		fflush(stdin);
		scanf("%d", &horasTrabajadas);
	}

	printf("\nIngrese sueldo del Empleado: ");
	fflush(stdin);
	scanf("%d", &sueldo);
	while(sueldo < 0){
		printf("Invalido. Reingrese Sueldo del Empleado: ");
		fflush(stdin);
		scanf("%d", &sueldo);
	}

	nuevoEmpleado = employee_newParametros(nuevoId, nombre, horasTrabajadas, sueldo);
	ll_add(pArrayListEmployee, nuevoEmpleado);
	if(nuevoEmpleado != NULL){
		exito = 1;
	}

    return exito;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	Employee* nuevoEmpleado;
	int tam;
	int exito = 0;

	tam = ll_len(pArrayListEmployee);

	printf("ID\t\tNOMBRE\t\tHORAS\t\tSUELDO\n\n");
	for(int i = 0; i < tam; i++){

		nuevoEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
		printf("%d\t\t%-10s\t\t%-5d\t\t%-5d\n", nuevoEmpleado->id, nuevoEmpleado->nombre, nuevoEmpleado->horasTrabajadas, nuevoEmpleado->sueldo);
		exito = 1;
	}
	return exito;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

