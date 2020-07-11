/**
*   @file Galaxia.h
*   @author Radoslaw Krzysztof Krolikowski
*   @date 06/2020
*   @brief Fichero de Cabecera del TDA Galaxia
*/

#ifndef __Galaxia_H__
#define __Galaxia_H__
#include "Pantalla.h"
#include "Personaje.h"

/**
*   @brief Puntero a estructura Galaxia.
*   Se empleará para manejar entidades de tipo Galaxia
*/
typedef struct GalaxiaRep * Galaxia;

/**
*   @brief Crea una nueva variable Galaxia y devuelve un puntero hacía ella.
*   Se reserva memoria con la función malloc().
*   @code
*   Galaxia galaxia = GalaxiaCrea(10);
*   @endcode
*   @param nmax Número de Estrellas que constituyen la Galaxia
*   @return Puntero a la nueva Galaxia creada.
*/
Galaxia GalaxiaCrea(int nmax);

/**
*   @brief Libera memoria perteneciente a la Galaxia.
*   Al estar compuesta por Estrellas, se utilizan funciones del TDA Estrella.
*   Se libera memoria con las funciones EstrellaLibera y free().
*   @code
*   GalaxiaLibera (g);
*   @endcode
*   @param g Variable perteneciente a la Galaxia
*/
void GalaxiaLibera (Galaxia g);

/**
*   @brief Inserta las Estrellas de las que está compuesta la Galaxia
*   Al estar compuesta de estrellas, se utilizan funciones del TDA Estrella.
*   @code
*   GalaxiaInserta(galaxia,estrellaImagen,rand()%(Pantalla_Anchura()-40),rand()%(Pantalla_Altura()-40),50,50);
*   @endcode
*   @param g Variable perteneciente a la Galaxia
*   @param i Imagen que representará la galaxia, en este caso la Estrella
*   @param x Posición horizontal de las estrellas de la galaxia
*   @param y Posición vertical de las estrellas de la galaxia
*   @param w Anchura de las estrellas de la galaxia
*   @param h Altura de las estrellas de la galaxia
*/
void GalaxiaInserta(Galaxia g, Imagen i, int x, int y, int w, int h);//

/**
*   @brief Dibuja las Estrellas de las que está compuesta la Galaxia en pantalla.
*   Al estar compuesta de estrellas, se utilizan funciones del TDA Estrella.
*   @code
*   GalaxiaDibuja(galaxia);
*   @endcode
*   @param g Variable perteneciente a la Galaxia
*/
void GalaxiaDibuja (Galaxia g);

/**
*   @brief Permite la colisión entre las estrellas de la Galaxia y el personaje.
*   Recoge las coordenadas de los dos y si coinciden, se produce el choque.
*   @code
*   GalaxiaColision(galaxia,personaje);
*   @endcode
*   @param g Variable perteneciente a la Galaxia
*   @param p Variable perteneciente al Personaje
*   @return Coordenadas del choque entre las Estrellas de la Galaxia y el Personaje.
*/
int GalaxiaColision (Galaxia g, Personaje p);//

#endif
