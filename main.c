/**
Practico de maquina 2
Grupo 7
Integrante: Wang Chih Wen
            Viluron Nicolas

Consignas del grupo:
 - Avance RAL: -5
 - Politica de reemplazo: mayor de los menores
**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <strings.h>
#include "articulo.h"
#include "menu.h"
#include "RAL.h"
#include "RAC.h"
#include "ABB.h"


int main(){
    int opc;
    RALineal ral;
    RACuadratico rac;
    ArbolBB abb;

    initRAL(&ral);
    initRAC(&rac);
    initABB(&abb);

    while(1){
        do{
            system("cls");
            printf("\n\n\n\t\t1 - Rebalse Abierto Lineal (RAL)\n\n\t\t2 - Rebalse Abierto Cuadratico (RAC)\n\n\t\t3 - Arbol Binario de Busqueda (ABB)\n\n\t\t4 - Salir\n\n\nIngrese la opcion: ");
        }while(!scanf("%d",&opc)||(opc>4)||(opc<=0));
        system("cls");
        switch(opc){
            case 1:
            case 2:
            case 3:{
                menu(&ral,&rac,&abb,opc);
                break;
            }
            case 4:{
                exit(1);
            }
        }
    }


    return 0;
}
