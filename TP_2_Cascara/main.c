#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    int flag=0;
    char seguir='s';
    EPersona lista[M];



    while(seguir=='s')
    {

        switch(menu())
        {
            case 1:
                system("cls");
                alta(lista);
                flag=1;
                break;
            case 2:
                system("cls");
                if(flag==1)
                {
                    baja(lista);
                }
                else
                {
                    printf("ERROR, no se ingresaron datos")
                }
                break;
            case 3:
                system("cls");
                if(flag==1)
                {
                   listar(lista);
                }
                 else
                {
                    printf("ERROR, no se ingresaron datos")
                }
                break;
            case 4:
                system("cls");
                if (flag==1)
                {
                    graficar(lista);
                }
                 else
                {
                    printf("ERROR, no se ingresaron datos")
                }
                break;
            case 5:
                system("cls");
                seguir = 'n';
                break;
            default:
                printf("ERROR, opcion invalida");
                break;
        }
    }

    return 0;
}
