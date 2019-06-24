#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "validaciones.h"
#include "Employee.h"
#include "controller.h"

int main()
{
    int option=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados!=NULL){
        do{
            system("cls");
            option=menu();
            switch(option)
            {
                case 1:
                    if(!(controller_loadFromText("data.csv",listaEmpleados))){
                        printf("\nProblemas para cargar el Archivo.csv No existe o esta corrupto\n\n");
                        system("pause");
                    }else{
                        printf("\nCarga del archivo con exito...\n\n");
                        system("pause");
                    }
                    break;
                case 2:
                    if(!(controller_ll_map(listaEmpleados)))
                    {
                        printf("\nProblemas para calcular el sueldo\n\n");
                        system("pause");
                    }else{
                        printf("\nSueldo Cargado info.csv creado...\n\n");
                        system("pause");
                    }
                    break;
                case 3:
                    ll_deleteLinkedList(listaEmpleados);
                    printf("\nHasta Luego :( \n");
                    break;
                default:
                    system("cls");
                    printf("Error reintentar...");
                    system("pause");
            }
        }while(option != 3);
    }else{
        printf("No se puedo generar linkedlist volver mas tarde..");
        system("pause");
    }
    return 0;
}
