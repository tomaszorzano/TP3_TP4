#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "validaciones.h"
#include "Employee.h"
#include "controller.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


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
                    if(!(controller_loadFromBinary("data.bin",listaEmpleados)))
                    {
                        printf("\nProblemas para cargar el Archivo.bin No existe o esta corrupto\n\n");
                        system("pause");
                    }else{
                        printf("\nCarga del archivo con exito...\n\n");
                        system("pause");
                    }
                    break;
                case 3:
                   // system("cls");
                    if(controller_addEmployee(listaEmpleados)){
                        printf("\nLa carga del empleado fue exitosa...\n");
                        system("pause");
                    }else{
                        printf("\nOcurrio un error y no se puedo agregar al empleado , volviendo al menu...\n");
                        system("pause");
                    }
                    break;
                case 4:
                    system("cls");
                    if(controller_editEmployee(listaEmpleados))
                    {
                        printf("Empleado editado con exito con exito...\n");
                        system("pause");
                    }else{
                        printf("No se encuentra el empleado o el ID no pertenece a ninguno...\n");
                        system("pause");
                    }
                    break;
                case 5:
                    system("cls");
                    if(controller_removeEmployee(listaEmpleados))
                    {
                        printf("Empleado eliminado con exito...\n");
                        system("pause");
                    }else{
                        printf("No se encuentra el empleado o el ID no pertenece a ninguno...\n");
                        system("pause");
                    }
                    break;
                case 6:
                    system("cls");
                    if(!(controller_ListEmployee(listaEmpleados))){
                        printf("Lista vacia cargar archivo o subir datos\n\n");
                    }
                    system("pause");
                    break;
                case 7:
                    system("cls");
                    if(controller_sortEmployee(listaEmpleados)){
                        printf("\nOrdenado....\n");
                        system("pause");
                    }
                    break;
                case 8:
                    if(controller_saveAsText("data1.csv",listaEmpleados)){
                        printf("\nEl archivo.csv se guardo de manera exitosa...\n");
                        system("pause");
                    }else{
                        printf("\nProblemas para guardar el archivo...\n");
                        system("pause");
                    }
                    break;
                case 9:
                    if(controller_saveAsBinary("data.bin",listaEmpleados)){
                        printf("\nEl archivo.bin se guardo de manera exitosa...\n");
                        system("pause");
                    }else{
                        printf("\nProblemas para guardar el archivo...\n");
                        system("pause");
                    }
                    break;
                case 10:
                    ll_deleteLinkedList(listaEmpleados);
                    printf("\nHasta Luego :( \n");
                    break;
                default:
                    system("cls");
                    printf("Error reintentar...");
                    system("pause");
            }
        }while(option != 10);
    }else{
        printf("No se puedo generar linkedlist volver mas tarde..");
        system("pause");
    }
    return 0;
}
