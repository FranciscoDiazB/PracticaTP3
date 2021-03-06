#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	char buffer[4][20];
	Employee* nuevoEmpleado;
	int cant;
	int exito = 0;
	int cont = 0;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

		while(!feof(pFile))
		{
			cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

			if( cant < 4){
				break;
			}

			nuevoEmpleado = employee_newParametrosString(buffer[0], buffer[1], buffer[2], buffer[3]);
			ll_add(pArrayListEmployee, nuevoEmpleado);
			if(cont == 10){
				break;
			}
			cont++;
			exito = 1;
		}
	}

	return exito;
}

int parser_SecondEmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* nuevoEmpleado;
	int cant;
	int exito = 0;
	int cont = 0;
	char id[20];
	char nombre[128];
	char horas[20];
	char sueldo[20];
	int cantidad;


	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		cantidad = ll_len(pArrayListEmployee);

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horas, sueldo);

		while(!feof(pFile))
		{
			cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horas, sueldo);

			if( cant < 4){
				break;
			}

			nuevoEmpleado = employee_newParametrosString(id, nombre, horas, sueldo);
			nuevoEmpleado->id = nuevoEmpleado->id + cantidad;
			ll_add(pArrayListEmployee, nuevoEmpleado);
			if(cont == 9){
				break;
			}
			cont++;
			exito = 1;
		}
	}

	return exito;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
