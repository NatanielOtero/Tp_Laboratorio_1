#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define M 20


typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;

}EPersona;

int menu();
/** Imprime el menu
 *
 * \param muestra las opciones y toma el valor
 *
 * \return devuelve la opcion del menu switch
 *
 */

void obtenerEspacioLibre(EPersona lista[]);
/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */

int buscarPorDni(EPersona lista[]);
/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
void alta(EPersona lista[]);
/**
 * Ingresa los datos
 * \param permite ingresar el nombre la edad y el dni
 * \param valida los valores
 * \return carga los valores en el array
 *
 */

void listar(EPersona lista[]);
/**
 * Imprime los nombres
 * \param ordena los nombres alfabeticamente
 * \return muestra los nombres de las personas ordenados con sus respectivos datos
 *
 */

void baja(EPersona lista[]);
/**
 * Elimina los datos almacenados en el array elegido
 * \param recibe el valor del indice de la funcion buscar por dni
 * \param cambia los valores del array por 0,incluido el estado.
 *
 *
 */

void graficar(EPersona lista[]);
/**
 * Grafica las personas por su edad
 * \param comprueba cuantas personas hay de cada rango de edad
 * \param las ordena y grafica un "*" por cada persona
 *
 *
 */








