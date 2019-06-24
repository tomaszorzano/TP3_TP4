#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char buffer[3][50];
    int cant,retorno=1;
    Employee* auxEmployee;
    fscanf(pFile,"%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2]);
    do{
        cant =fscanf(pFile,"%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2]);
        fflush(stdin);
        if(cant == 3){

            auxEmployee = employee_newParametros(buffer[0],buffer[1],buffer[2]);
            if(auxEmployee==NULL){
                retorno=0;
                break;
            }
            if(ll_add(pArrayListEmployee, auxEmployee))
            {
                retorno=0;
                break;
            }
        }else{
            retorno=0;
            break;
        }

   } while(!feof(pFile));
    return retorno;
}



