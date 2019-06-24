#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "validaciones.h"
int menu(){
    int opcion=0;
    printf("/*********************************************************\n\n");
    printf("Menu:\n\n");
    printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf(" 2. Calcular sueldo\n");
    printf(" 3. Salir\n\n");
    printf("***********************************************************/");
    utn_getEntero(&opcion,"\n\nSeleccione una opcion: ","\n\nERROR las opciones son numericas del 1 al 3: ",1,3);
    return opcion;
}
Employee* employee_new()
{
    Employee* persona=(Employee*) calloc (1,sizeof(Employee));

    if(persona == NULL)
    {
        printf("No se pudo conseguir espacio liberar memoria o reiniciar el programa...");
        system("Pause");
//        persona->id=0;
//        strcpy(persona->nombre, " "); ESTO ESTA POR QUE LO HICE CON MALLOC INICIALMENTE Y NO QUERIA USAR UN SETTER
//        persona->horasTrabajadas=0;   YA QUE LA CONDICION ERA QUE IBA A SER MAYOR QUE CERO
//        persona->sueldo=0;
    }
    return persona;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    Employee* persona=employee_new();
    int todoOk=0;
    if(employee_setId(persona,atoi(idStr))){
        if(employee_setNombre(persona,nombreStr)){
            if(employee_setHorasTrabajadas(persona,atoi(horasTrabajadasStr))){
                    todoOk=1;
            }
        }
    }
    if(todoOk==0)
    {
        persona = NULL;
    }
    return persona;
}
int employee_setId(Employee* this,int id){
    int ok=0;
    if(this!=NULL&&id>0){
        this->id=id;
        ok=1;
    }
    return ok;
}
int employee_getId(Employee* this,int* id)
{
    int ok=0;
    if(this!=NULL&&id!=NULL){
        *id=this->id;
        ok=1;
    }
    return ok;
}
int employee_setNombre(Employee* this,char* nombre)
{
    int ok=0;
    if(this!=NULL&&nombre!=NULL){
        strcpy(this->nombre,nombre);
        ok=1;
    }
    return ok;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int ok=0;
    if(this!=NULL&&nombre!=NULL){
        strcpy(nombre,this->nombre);
        ok=1;
    }
    return ok;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    int ok=0;
    if(this!=NULL&&horasTrabajadas>0){
        this->horasTrabajadas=horasTrabajadas;
        ok=1;
    }
    return ok;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int ok=0;
    if(this!=NULL&&horasTrabajadas!=NULL){
        *horasTrabajadas=this->horasTrabajadas;
        ok=1;
    }
    return ok;
}
int employee_setSueldo(Employee* this,int sueldo){
    int ok=0;
    if(this!=NULL&&sueldo>0){
        this->sueldo=sueldo;
        ok=1;
    }
    return ok;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int ok=0;
    if(this!=NULL&&sueldo!=NULL){
        *sueldo=this->sueldo;
        ok=1;
    }
    return ok;
}
void mostrarEmployee(Employee* emp){
    int id,sueldo,horasTrabajadas;
    char nombre[128];
    if(emp!=NULL){
        employee_getId(emp,&id);
        employee_getHorasTrabajadas(emp,&horasTrabajadas);
        employee_getSueldo(emp,&sueldo);
        employee_getNombre(emp,nombre);
        printf("%d %15s %d   %d\n",id,nombre,horasTrabajadas,sueldo);

    }
}
void mostrarEmployees(LinkedList* lista){
    int i;
    Employee* p;
    for(i=0; i <=ll_len(lista); i++){
        p = (Employee*)ll_get(lista, i);
        mostrarEmployee(p);

    }
}

int employee_sueldoCalculo(void* employeeA)
{
    int retorno=0,horAux1=0,sueldo=1,sueldo2=1,horAux2=0;
    if(employeeA!=NULL){
        employee_getHorasTrabajadas(((Employee*)employeeA),&horAux1);
        if(horAux1<=176){
            sueldo=180*horAux1;
            employee_setSueldo(((Employee*)employeeA),sueldo);
            retorno = 1;
        }
        else if(horAux1>=176&&horAux1<=208){
            sueldo=180*176;
            horAux1=horAux1-176;
            sueldo2=270*horAux1;
            sueldo=sueldo+sueldo2;
            employee_setSueldo(((Employee*)employeeA),sueldo);
            retorno = 1;
        }
        else{
            sueldo=180*176;
            sueldo2=270*32;
            sueldo=sueldo+sueldo2;
            horAux2=horAux1-208;
            sueldo2=360*horAux2;
            sueldo=sueldo+sueldo2;
            employee_setSueldo(((Employee*)employeeA),sueldo);
            retorno = 1;
        }
    }
    return retorno;
}




