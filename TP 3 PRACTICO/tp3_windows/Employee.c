#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new(){

   Employee* nuevoEmpleado = (Employee*) malloc (sizeof(Employee));

   if(nuevoEmpleado != NULL){

        employee_setId(nuevoEmpleado, 0);
        employee_setNombre(nuevoEmpleado, " ");
        employee_setHorasTrabajadas(nuevoEmpleado, 0);
        employee_setSueldo(nuevoEmpleado, 0);
   }

   return nuevoEmpleado;
}

Employee* employee_newParametros(int id, char* nombre, int horasTrabajadas, int sueldo){

	Employee* nuevoEmpleado = NULL;

	nuevoEmpleado =	employee_new();

	if(nuevoEmpleado != NULL){

		if(!(employee_setId(nuevoEmpleado, id) &&
			employee_setNombre(nuevoEmpleado, nombre) &&
			employee_setHorasTrabajadas(nuevoEmpleado, horasTrabajadas) &&
			employee_setSueldo(nuevoEmpleado, sueldo)))
		{
			printf("\nFallaron Setters\n");
			free(nuevoEmpleado);
			nuevoEmpleado = NULL;
		}
	}

	return nuevoEmpleado;
}

Employee* employee_newParametrosString(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr){

	Employee* nuevoEmpleado = NULL;

	nuevoEmpleado =	employee_new();

	if(nuevoEmpleado != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL){

		if(!(employee_setIdStr(nuevoEmpleado, idStr) &&
				employee_setNombre(nuevoEmpleado, nombreStr) &&
				employee_setHorasTrabajadasStr(nuevoEmpleado, horasTrabajadasStr) &&
				employee_setSueldoStr(nuevoEmpleado, sueldoStr)))
		{
			printf("\nFallaron Setters\n");
			free(nuevoEmpleado);
			nuevoEmpleado = NULL;
		}
	}

	return nuevoEmpleado;
}

int employee_setId(Employee* this,int id){

	int retorno = 0;

	if(this != NULL && id > 0){

		this->id = id;
		retorno = 1;
	}

	return retorno;
}

int employee_setIdStr(Employee* this, char* id){

	int retorno = 0;

	if(this != NULL && id != NULL){

		this->id = atoi(id);
		retorno = 1;
	}

	return retorno;
}

int employee_getId(Employee* this,int* id){

	int retorno = 0;

	if(this != NULL && id != NULL){

		*id = this->id;
		retorno = 1;
	}

	return retorno;
}


int employee_setNombre(Employee* this,char* nombre){

	int retorno = 0;

	if(this != NULL && nombre != NULL){

		if(strlen(nombre) < 128){

			strcpy(this->nombre, nombre);
			retorno = 1;
		}
	}

	return retorno;
}

int employee_getNombre(Employee* this,char* nombre){

	int retorno = 0;

	if(this != NULL && nombre != NULL){

		if(strlen(nombre) < 128){

			strcpy(nombre, this->nombre);
			retorno = 1;
		}
	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){

	int retorno = 0;

	if(this != NULL && horasTrabajadas > 0){

		this->horasTrabajadas = horasTrabajadas;
		retorno = 1;
	}

	return retorno;

}

int employee_setHorasTrabajadasStr(Employee* this, char* horasTrabajadas){

	int retorno = 0;

	if(this != NULL && horasTrabajadas != NULL){

		this->horasTrabajadas = atoi(horasTrabajadas);
		retorno = 1;
	}

	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){

	int retorno = 0;

	if(this != NULL && horasTrabajadas != NULL){

		*horasTrabajadas = this->horasTrabajadas;
		retorno = 1;
	}

	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo){

	int retorno = 0;

	if(this != NULL && sueldo > 0){

		this->sueldo = sueldo;
		retorno = 1;
	}

	return retorno;
}

int employee_setSueldoStr(Employee* this, char* sueldo){

	int retorno = 0;

	if(this != NULL && sueldo > 0){

		this->sueldo = atoi(sueldo);
		retorno = 1;
	}

	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo){

	int retorno = 0;

	if(this != NULL && sueldo != NULL){

		*sueldo = this->sueldo;
		retorno = 1;
	}

	return retorno;
}

void employee_delete(Employee* this){

	if(this != NULL){

		free(this);
	}
}

/*int employee_showAnEmployee(Employee* this){

	int exito = 0;
	int idE = 0;
	char nombreE[128] = " ";
	int horasTE = 0;
	int sueldoE = 0;

	if(this != NULL){

		if(employee_getId(this, &idE) &&
			employee_getNombre(this, nombreE) &&
			employee_getHorasTrabajadas(this, &horasTE) &&
			employee_getSueldo(this, &sueldoE)){

			printf("ID		NOMBRE		HORAS		SUELDO\n\n");
			printf("%d		%s		%d		%d\n", idE, nombreE, horasTE, sueldoE);
			exito = 1;
		}

	}

	return exito;
}*/
