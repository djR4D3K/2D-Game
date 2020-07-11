/**
*   @file Personaje.h
*   @author Radoslaw Krolikowski
*   @date 06/2020
*   @brief Fichero cabecera del TDA Personaje
*/

#ifndef __Personaje_H__
#define __Personaje_H__
#include "Pantalla.h"

/**
*   @brief Puntero a estructura Personaje.
*   Se emplerá para manejar entidades de tipo Personaje.
*/
typedef struct PersonajeRep * Personaje;

/**
*   @brief Crea una nueva variable de tipo Personaje y devuelve un puntero hacía ella.
*   Esta función asigna memoria dinámica mediante la función malloc().
*   @code
*   PersonajeCrea(personajeImagen,rand()%(Pantalla_Anchura()-50),Pantalla_Altura()-50,50,50);
*   @endcode
*   @param i Variable en la que está guardada la imagen que se emplea para representar el personaje
*   @param x Coordenada horizontal donde aparecerá el personaje
*   @param y Coordenada vertical donde aparecerá el personaje
*   @param w Anchura del personaje
*   @param h Altura del personaje
*   @return Puntero al nuevo personaje
*/
Personaje PersonajeCrea (Imagen i, int x, int y, int w, int h);

/**
*   @brief Libera la memoria ocupada por el personaje.
*   @code
*   PersonajeLibera(personaje);
*   @endcode
*   @param  p Variable que contiene el personaje que se desea liberar
*/
void PersonajeLibera (Personaje p);

/**
*   @brief Función encargada del movimiento del personaje por la pantalla.
*   @code
*   PersonajeMueve(personaje,45,45);
*   @endcode
*   @param p Variable que contiene el personaje que se desea mover
*   @param vx Velocidad en horizontal
*   @param vy Velocidad en vertical
*/
void PersonajeMueve (Personaje p, int vx, int vy);

/**
*   @brief Función encargada de mostrar el personaje por pantalla
*   @code
*   PersonajeDibuja(personaje);
*   @endcode
*   @param p Variable que contiene el personaje que se desea mostrar en pantalla
*/
void PersonajeDibuja (Personaje p);

/**
*   @brief Consigue las coordenadas y las medidas del personaje.
*   Sirve para permitir la colisión con otros elementos.
*   @param p Variable que contiene al personaje
*   @param x Posición horizontal del personaje
*   @param y Posición vertical del personaje
*   @param w Anchura del personaje
*   @param h Altura del personaje
*   @return Posición del personae en el plano
*/
int PersonajeColision(Personaje p, int x, int y, int w, int h);

#endif
