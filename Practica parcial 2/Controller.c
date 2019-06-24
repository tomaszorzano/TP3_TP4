
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "controller.h"
#include "validaciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{

    FILE* pFile;
    int retorno=1;
    pFile = fopen(path, "r");
    if(pFile!=NULL&&path!=NULL)
    {
        if(!(parser_EmployeeFromText(pFile,pArrayListEmployee)))
            retorno=0;
    }
    fclose(pFile);
    return retorno;
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
    FILE* pFile;
    pFile = fopen(path, "w");
    int retorno=0;
    Employee* p;
    int i;
    if(path!=NULL&&pFile!=NULL&&pArrayListEmployee!=NULL){
        fprintf(pFile,"%s,%s,%s,%s\n","id","nombre","horasTrabajadas","sueldo");
        for(i=0; i<ll_len(pArrayListEmployee);i++){
            p = (Employee*)ll_get(pArrayListEmployee, i);
            fprintf(pFile,"%d,%s,%d,%d\n",p->id,p->nombre,p->horasTrabajadas,p->sueldo);
        }
        if(i==ll_len(pArrayListEmployee)){
            retorno=1;
        }
    }
    fclose(pFile);
    return retorno;
}
int controller_ll_map(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    if(pArrayListEmployee == NULL){
        printf("No hay datos en la lista.\n");
    }
    else
    {
        LinkedList* newLinker=ll_clone(pArrayListEmployee);
        if(newLinker!=NULL){
            ll_map(newLinker,employee_sueldoCalculo);
            if(controller_saveAsText("info.csv",newLinker))
                retorno=1;
            ll_deleteLinkedList(newLinker);
        }
    }
    return retorno;
}
