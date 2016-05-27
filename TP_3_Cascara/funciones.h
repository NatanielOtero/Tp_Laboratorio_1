#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


#define M 2

typedef struct{
    char titulo[21];
    char genero[21];
    int duracion;
    char descripcion[51];
    int puntaje;
    char linkImagen[51];
    int estado;
}EMovie;

/**
 * Inicializa estados para saber si la posicion esta cargada o no.
 *
 *
 */

void estado(EMovie movie[]);
/**
 * Permite modificar una pelicua
 * \param carga el titulo a modificar en un auxiliar
 * \param lo compara con la estructura
 */


void modificar(EMovie movie[],FILE *f);
/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie movie[],FILE *f);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie[],FILE *f);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char *nombre);
/**
 *
 * \param cadena de caracteres a validar
 * \param maximo de caracteres
 *
 *
 */

void val_tam(char x[],int tam);
/**
 *
 * \param entero a validar
 * \param rango minimo
 * \param rango maximo
 * \return entero validado
 *
 */


int val_Rangoint(int,int,int);
/**
 *
 *
 * \param entero a validar
 * \return entero validado
 *
 */


int val_Enteros(int);


#endif // FUNCIONES_H_INCLUDED
