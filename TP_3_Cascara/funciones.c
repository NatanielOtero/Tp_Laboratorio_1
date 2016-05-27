#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"


#define M 2

void estado(EMovie movie[])
{
    int i;

    for(i=0;i<M;i++)
    {
        movie[i].estado = 0;

    }
}


int agregarPelicula(EMovie movie[],FILE *f)
{
    int i;

    estado(movie);

    for(i=0;i<M;i++)
    {
       if(movie[i].estado == 0)
       {
            printf("Titulo de La pelicula: \n");
            fflush(stdin);
            gets(movie[i].titulo);
            strlwr(movie[i].titulo);
            val_tam(movie[i].titulo,21);
            printf("Genero de la pelicula: \n");
            fflush(stdin);
            gets(movie[i].genero);
            val_tam(movie[i].genero,21);
            printf("Duracion de la pelicula(min): \n");
            scanf("%d",&movie[i].duracion);
            movie[i].duracion = val_Enteros(movie[i].duracion);
            printf("Descripcion de la pelicula: \n");
            fflush(stdin);
            gets(movie[i].descripcion);
            val_tam(movie[i].descripcion,51);
            printf("Puntaje de la pelicula(del 1 al 10):  \n");
            scanf("%d",&movie[i].puntaje);
            movie[i].puntaje = val_Rangoint(movie[i].puntaje,1,10);
            printf("Portada de la pelicula: \n");
            fflush(stdin);
            gets(movie[i].linkImagen);
            val_tam(movie[i].linkImagen,51);
            movie[i].estado = 1;

            fseek(f,0L,SEEK_END);
            fwrite(&movie,sizeof(EMovie),1,f);



            break;
       }


    }
    return 0;



}

int borrarPelicula(EMovie movie[],FILE *f)
{
    int i;
    char aux[20];

    printf("Ingrese el titulo de la pelicula a eliminar");
    fflush(stdin);
    gets(aux);
    strlwr(aux);

    for(i=0;i<M;i++)
    {
        if(strcmp(movie[i].titulo,aux)== 0 && movie[i].estado == 1)
        {
            movie[i].estado = 0;
            fseek(f,(-1)*sizeof(EMovie),SEEK_CUR);
            fwrite(&movie,sizeof(EMovie),1,f);

        }
    }

    return 0;


}
void modificar(EMovie movie[],FILE *f)
{
    int i=0;
    char aux[20];

    printf("Ingrese el titulo de la pelicula a modificar");
    fflush(stdin);
    gets(aux);
    strlwr(aux);

    rewind(f);
    while(!feof(f))
    {

        fread(&movie,sizeof(EMovie),1,f);
        if(strcmp(aux,movie[i].titulo)==0 && movie[i].estado==1)
        {
            printf("Ingrese el nuevo titulo");
            fflush(stdin);
            gets(movie[i].titulo);
            val_tam(movie[i].titulo,21);
            printf("Ingrese genero: ");
            fflush(stdin);
            gets(movie[i].genero);
            val_tam(movie[i].genero,21);
            printf("Ingrese duracion(min): ");
            scanf("%d",&movie[i].duracion);
            val_Enteros(movie[i].duracion);
            printf("Ingrese descripcion: ");
            fflush(stdin);
            gets(movie[i].descripcion);
            val_tam(movie[i].descripcion,51);
            printf("Ingrese puntaje(del 1 al 10): ");
            scanf("%d",&movie[i].puntaje);
            val_Rangoint(movie[i].puntaje,1,10);
            printf("Link de imagen: ");
            fflush(stdin);
            gets(movie[i].linkImagen);
            val_tam(movie[i].linkImagen,51);

            fseek(f,(-1)*sizeof(EMovie),SEEK_CUR);
            fwrite(&movie,sizeof(EMovie),1,f);
            break;


        }
        i++;


    }



}


void generarPagina(EMovie movie[], char *nombre)
{
     FILE *f;
     int i;



     f = fopen("Index.html","w");

     if(f == NULL)
     {
          printf("No se pudo abrir el archivo\n");
          exit(1);
     }
     else
     {
         rewind(f);

         fprintf(f,"<!DOCTYPE html>\n");
         fprintf(f,"<html lang='en'>\n");
         fprintf(f,"<head>");
         fprintf(f,"<meta charset='utf-8'> \n");
         fprintf(f,"<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
         fprintf(f,"<meta name='viewport' content='width=device-width, initial-scale=1'>\n");
         fprintf(f,"<title>Lista peliculas</title>\n");
         fprintf(f,"<link href='css/bootstrap.min.css' rel='stylesheet'>\n");
         fprintf(f,"<link href='css/custom.css' rel='stylesheet'>\n");
         fprintf(f,"</head>\n");
         fprintf(f,"<body>\n");
         fprintf(f,"<div class='container'>\n");
         fprintf(f,"<div class='row'>\n");


         for(i=0;i<101;i++)
         {
            if(movie[i].estado == 1)
            {
                fprintf(f,"<article class='col-md-4 article-intro'>\n");
                fprintf(f,"<a href='#'>");
                fprintf(f,"<img class='img-responsive img-rounded' src= %s alt=''>\n",movie[i].linkImagen);
                fprintf(f,"</a>\n");
                fprintf(f,"<h3>\n");
                fprintf(f,"<a href='#'>%s</a>\n",movie[i].titulo);
                fprintf(f,"</h3>\n");
                fprintf(f,"<ul>");
                fprintf(f,"<li>Genero:%s</li>\n",movie[i].genero);
                fprintf(f,"<li>Puntaje:%d</li>\n",movie[i].puntaje);
                fprintf(f,"<li>Duracion:%d</li>\n",movie[i].duracion);
                fprintf(f,"</ul>\n");
                fprintf(f,"<p> %s </p>\n",movie[i].descripcion);
                fprintf(f,"</article>\n");
                fprintf(f,"\n");

            }


         }
         fprintf(f,"</div>\n");
         fprintf(f,"</div>\n");
         fprintf(f,"<script src='js/jquery-1.11.3.min.js'></script>\n");
         fprintf(f,"<script src='js/bootstrap.min.js'></script>\n");
         fprintf(f,"<script src='js/ie10-viewport-bug-workaround.js'></script>\n");
         fprintf(f,"<script src='js/holder.min.js'></script>\n");
         fprintf(f,"</body>\n");
         fprintf(f,"</html>\n");







     }


      printf("Listado creado con exito\n");
      system("pause");
}
void val_tam(char x[],int tam)
{
    while(strlen(x)>tam-1)
    {
        printf("Error.Reingrese una cadena que no exada los %d caracteres: ",tam);
        fflush(stdin);
        gets(x);
    }
}
int val_Rangoint(int dato, int min, int max)
{
      while (dato<min || dato>max)
        {
          printf("Error. Reingrese: ");
          scanf("%d",&dato);
          if(dato==isdigit(dato))
            {
                printf("Error,ingerese numero");
                scanf("%d",&dato);
            }

        }
    return dato;
}
int val_Enteros(int dato)
{
    while(dato==isdigit(dato))
            {
                printf("Error,ingerese numero");
                scanf("%d",&dato);
            }

    return dato;
}
