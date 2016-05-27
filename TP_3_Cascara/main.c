#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define M 2



int main()
{
    FILE *f;
    EMovie movie[M];


    char seguir='s';
    int opcion=0,flag=0,flag2=0;





         f=fopen("Index.html", "wb+");
              if(f==NULL)
              {
                  printf("Memoria llena, error;");
              }


            while(seguir=='s')
                {
                    printf("1- Agregar pelicula\n");
                    printf("2- Borrar pelicula\n");
                    printf("3- Modificar pelicula\n");
                    printf("4- Generar pagina web\n");
                    printf("5- Salir\n");

                    scanf("%d",&opcion);

                        switch(opcion)
                        {
                            case 1:
                                    if(flag2<101)
                                    {
                                        agregarPelicula(movie,f);
                                        flag=1;
                                        flag2++;
                                        break;
                                    }
                                    else
                                    {
                                        printf("Error,solo se permite cargar 100 peliculas");
                                        break;
                                    }
                            case 2:
                                    if(flag==1)
                                    {
                                        borrarPelicula(movie,f);
                                        break;
                                    }
                                    else
                                    {
                                        printf("No se realizo la carga");
                                        break;
                                    }
                            case 3:
                                    if(flag==1)
                                    {
                                        modificar(movie,f);
                                        break;
                                    }
                                    else
                                    {
                                        printf("No se realizo la carga");
                                        break;
                                    }
                               break;
                            case 4:
                                    if(flag==1)
                                    {
                                        generarPagina(movie,"index.html");
                                        break;
                                    }
                                    else
                                    {
                                        printf("No se realizo la carga");
                                        break;
                                    }

                            case 5:
                                    seguir = 'n';
                                    break;
                            default:
                                    printf("Opcion invalida");
                                    break;
                        }
                }


        fclose(f);
        return 0;
    }


