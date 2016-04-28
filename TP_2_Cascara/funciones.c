#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funciones.h"

#define M 20

int menu()
{
    int opcion;


        printf("----------------------------------------|");
        printf("\nBienvenido al menu de opciones          |\n");
        printf("----------------------------------------|\n");
        printf("1- Agregar persona                      |\n");
        printf("2- Borrar persona                       |\n");
        printf("3- Imprimir lista ordenada por  nombre  |\n");
        printf("4- Imprimir grafico de edades           |\n");
        printf("----------------------------------------|\n");
        printf("5- Salir                                |\n");
        printf("----------------------------------------|\n");

        scanf("%d",&opcion);


    return opcion;

}
void obtenerEspacioLibre(EPersona lista[])
{
    int i;
    for(i=0; i<M; i++)
    {
        lista[i].estado=0;
        lista[i].dni=0;
        lista[i].edad=0;

    }
}

void alta(EPersona lista[])
{
    int i;



    for(i=0; i<M; i++)
    {
        if(lista[i].estado==0)
        {
            printf("\n Ingrese nombre: ");
            fflush(stdin);
            gets(lista[i].nombre);

            printf("\n Ingrese edad: ");
            scanf("%d",&lista[i].edad);
            while(lista[i].edad<0 || lista[i].edad>99)
            {
                printf("\n ERROR edad invalida, reingrese: ");
                scanf("%d",&lista[i].edad);
            }



            printf("\n Ingrese dni: ");
            scanf("%li", &lista[i].dni);
            while(lista[i].dni>99999999 || lista[i].dni<1000000)
            {
                printf("\n ERROR, DNI invalido, reingrese: ");
                scanf("%li",& lista[i].dni);
            }






            lista[i].estado=1;
            break;
        }
    }
    if(i==M)
    {
        printf("\n Capacidad agotada!!!");
    }
}
int buscarPorDni(EPersona lista[])
{
    int indice=0,i;
    long int dniaux;

        printf("\n Ingrese dni a buscar: ");
        scanf("%li",&dniaux);
        for(i=0;i<M;i++)
        {
            if(dniaux == lista[i].dni)
            {
               indice = i;
               break;
            }
        }
    return indice;
}
void baja(EPersona lista[])
{
    int i,auxInd;

    auxInd = buscarPorDni(lista);


    for(i=0; i<M; i++)
    {
        if( auxInd == i && lista[auxInd].estado==1)
        {

            lista[i].estado=0;
            lista[i].dni=0;
            lista[i].edad=0;
            strcpy(lista[i].nombre,"-");

            break;
        }

    }
    if(i==M)
    {
       printf("\n No existe el dni buscado");
    }



}
void listar(EPersona lista[])
{
    int i, j;
    EPersona auxP;

    for(i=0; i<M-1; i++)
    {
        for(j=i+1; j<M; j++)
        {
            if(lista[j].estado ==1)
            {
                if(strcmp(lista[i].nombre,lista[j].nombre)>0)
                {
                    auxP=lista[i];
                    lista[i]=lista[j];
                    lista[j]=auxP;
                }
            }

        }
    }

    for(i=0;i<M;i++)
    {


        if(lista[i].estado==1)
        {
            printf(" Nombre: %s DNI: %li edad: %d \n",lista[i].nombre,lista[i].dni,lista[i].edad);

        }



    }

}
void graficar(EPersona lista[])
{
    int menores = 0 ,mayores = 0,viejos = 0,i,mayor=0,flag=0;




    for(i=0;i<M;i++)
    {
        if(lista[i].estado == 1)
        {
            if(lista[i].edad < 19 )
           {
            menores++;
           }
        if(lista[i].edad > 18 && lista[i].edad < 36)
            {
                mayores++;
            }
        if(lista[i].edad > 35)
            {
                    viejos++;
            }

        }

    }

    if(menores > mayores && menores > viejos)
    {
        mayor = menores;
    }
    else
    {
                if( mayores > menores && mayores >= viejos)
                    {
                        mayor = mayores;
                    }
                     else
                       {

                        mayor = viejos;
                       }
     }
     for(i=mayor; i>0; i--)
        {
        if(i<= menores){
            printf("*");
        }
        if(i<= mayores)
        {
            flag=1;
            printf("\t*");
        }
        if(i<= viejos)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }

        printf("\n");
    }
    printf("<18\t19-35\t>35\n");



}
