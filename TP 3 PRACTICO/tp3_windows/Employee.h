#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

}Employee;

Employee* employee_new();
Employee* employee_newParametros(int id, char* nombreStr, int horasTrabajadas, int sueldo);
Employee* employee_newParametrosString(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_setIdStr(Employee* this, char* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_setHorasTrabajadasStr(Employee* this, char* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
int employee_setSueldoStr(Employee* this, char* sueldo);

int employee_showOneEmployee(Employee* this);

#endif // employee_H_INCLUDED
