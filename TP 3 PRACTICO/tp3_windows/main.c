#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int menu();

int main()
{
	setbuf(stdout, NULL);

    char respuesta = 'n';
    int flagText = 0;
    int opcionAlta;
    int flagAlta = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do {

    	switch(menu()){

    	case 1:
    		if(flagAlta == 0){

				if(controller_loadFromText("data.csv", listaEmpleados) != 0){
					printf("\nLos datos del archivo cargados en la Lista");
					flagText = 1;
				}
    		}
    		else{
    			if(controller_SecondloadFromText("data.csv", listaEmpleados) != 0){
    				printf("\nLos datos del archivo fueron cargados a una Lista que ya tenia datos en ella.");
    				flagText = 1;
    			}
    		}
    		printf("\n\n");
    		system("pause");
    		break;

    	case 2:
    		controller_loadFromBinary("data.csv", listaEmpleados);
    		printf("\n\n");
    		system("pause");
    		break;

    	case 3:
    		if(flagText == 0){
    			printf("No hay ningun dato de archivos cargados en el sistema. Esta seguro que desea continuar. Puede suceder que pierda los datos\n\n");
    			printf("1. SI, DESEO CONTINUAR CON EL ALTA.\n");
    			printf("2. NO, PREFIERO VOLVER AL MENU.\n\n");
    			printf("Ingrese la opcion: ");
    			scanf("%d", &opcionAlta);
    			if(opcionAlta == 1){
    				if(controller_addEmployee(listaEmpleados) != 0){
    					printf("\nAlta exitosa");
    					flagAlta = 1;
    				}
    			}
    			else{
    				printf("\n\nAhora vuelve al menu.");
    			}
    		}
    		else{
				if(controller_addEmployee(listaEmpleados) != 0){
					printf("\nAlta exitosa");
					flagAlta = 1;
				}
    		}
    		printf("\n\n");
    		system("pause");
    		break;

    	case 4:

    		printf("\n\n");
    		system("pause");
    		break;

    	case 5:

    		printf("\n\n");
    		system("pause");
    		break;

    	case 6:
    		if(controller_ListEmployee(listaEmpleados) == 0){
    		    printf("\nNo hay datos cargados en la Lista.");
    		}
    		printf("\n\n");
    		system("pause");
    		break;

    	case 7:

    		printf("\n\n");
    		system("pause");
    		break;

    	case 8:
    		printf("\nEsta seguro que desea salir? Oprima la tecla 's' desea salir\n");
    		printf("De lo contrario oprima la tecla 'n' (minuscula)");
    		fflush(stdin);
    		respuesta = getchar();
    		printf("\n\n");
    		break;

    	case 9:

    		printf("\n\n");
    		system("pause");
    		break;

    	case 10:
    		printf("\nEsta seguro que desea salir? Oprima la tecla 's' desea salir\n");
    		printf("De lo contrario oprima la tecla 'n' (minuscula)\n");
    		fflush(stdin);
    		respuesta = getchar();
    		printf("\n\n");
    		system("pause");
    		break;

    	default:
    		printf("\n");
    		printf("Dato invalido. Reingrese numero\n");
    		system("pause");

    	}

    } while(respuesta == 'n');
    return 0;
}

int menu(){

	int opcion;

	printf("\n");
	printf("\t\t**** Menu ****");
	printf("\n\n");
	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
	printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
	printf("3. Alta de empleado\n");
	printf("4. Modificar datos de empleado\n");
	printf("5. Baja de empleado\n");
	printf("6. Listar empleados\n");
	printf("7. Ordenar empleados\n");
	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
	printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
	printf("10. Salir\n\n\n");

	printf("Ingrese la opcion correspondiente: ");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;

}

