/*
 * parser.h
 *
 *  Created on: 2 nov. 2021
 *      Author: Asus
 */
#include "LinkedList.h"
#include "Employee.h"

#ifndef PARSER_H_
#define PARSER_H_

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

int parser_SecondEmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
