/**
*   @file Estrella.h
*   @author Radoslaw Krzysztof Krolikowski
*   @date   04/2020
*   @brief  Fichero de Cabecera del TDA Estrella.
*/

#ifndef __Estrella_H__
#define __Estrella_H__
#include "Pantalla.h"
#include "Personaje.h"

/**
*   @brief Puntero a estructura Estrella
*   Se empleará para manejar entidades de tipo Estrella
*/
typedef struct EstrellaRep * Estrella;

/**
*   @brief Crea una nueva variable Estrella y devuelve un puntero hacia ella.
*   Esta función asigna memoria mediante la función malloc().
*   @code
*   Estrella est = EstrellaCrea (Pantalla_ImagenLee("estrella.bmp",255), rand( % (Pantalla_Anchura()-50),Pantalla_Altura()-50,50,50));
*   @endcode
*   @param i Imagen que representará la estrella en el juego
*   @param x Coordenada horizontal donde aparece la estrella
*   @param y Coordenada vertical donde aparece la estrella
*   @param w Ancho que tendrá la estrella
*   @param h Alto que tendrá la estrella
*   @return Puntero a la nueva Estrella creada
*/
Estrella EstrellaCrea (Imagen i, int x, int y, int h, int w);

/**
*   @brief Dibuja la estrella en pantalla.
*   Para ello, se usa la función Pantalla_ImagenDibuja.
*   @code
*   EstrellaDibuja(est);
*   @endcode
*   @param est Variable perteneciente a la Estrella
*/
void EstrellaDibuja (Estrella est);

/**
*   @brief Libera memoria perteneciente a la Estrella.
*   Para ello, se emplea la función free().
*   @code
*   EstrellaLibera(est);
*   @endcode
*   @param est Variable perteneciente a la Estrella.
*/
void EstrellaLibera (Estrella est);

/**
*   @brief Permite el choque entre la Estrella y el Personaje.
*   Recoge las coordenadas de los dos y si coinciden, se produce el choque.
*   @code
*   EstrellaColision (est, p);
*   @endcode
*   @param est Variable pertenciente a la Estrella
*   @param p Variable perteneciente al Personaje
*   @return Coordenadas del choque entre la Estrella y el Personaje.
*/
int EstrellaColision (Estrella est, Personaje p);

#endif
