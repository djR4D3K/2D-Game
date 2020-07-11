/**
*   @file Enemigo.h
*   @author Radoslaw Krzysztof Krolikowski
*   @date   04/2020
*   @brief  Fichero de Cabecera del TDA Enemigo.
*/

#ifndef __Enemigo_H__
#define __Enemigo_H__
#include "Pantalla.h"
#include "Personaje.h"

/**
*   @brief Puntero a estructura Enemigo
*   Se empleará para manejar entidades de tipo Enemigo
*/
typedef struct EnemigoRep * Enemigo;

/**
*   @brief Crea una nueva variable Enemigo y devuelve un puntero hacia ella.
*   Esta función asigna memoria mediante la función malloc().
*   @code
*   Enemigo e = EnemigoCrea (Pantalla_ImagenLee("Enemigo.bmp",255), rand( % (Pantalla_Anchura()-50),Pantalla_Altura()-50,50,50, 75, 75));
*   @endcode
*   @param i Imagen que representará al enemigo en el juego
*   @param x Coordenada horizontal donde aparece el enemigo
*   @param y Coordenada vertical donde aparece el enemigo
*   @param w Ancho que tendrá el enemigo
*   @param h Alto que tendrá el enemigo
*   @param vx Velocidad de movimiento horizontal
*   @param vy Velocidad de movimiento vertical
*   @return Puntero al nuevo Enemigo creado
*/
Enemigo EnemigoCrea (Imagen i, int x, int y, int w, int h, int vx, int vy);

/**
*   @brief Libera memoria perteneciente al Enemigo.
*   Esta función emplea la función free() para liberar memoria.
*   @code
*   EnemigoLibera(e);
*   @endcode
*   @param e Variable perteneciente al Enemigo
*/
void EnemigoLibera (Enemigo e);

/**
*   @brief Mueve el Enemigo por la pantalla
*   @code
*   EnemioMueve(e);
*   @endcode
*   @param e Variable perteneciente al Enemigo
*   @return Puntero al Enemigo
*/
void EnemigoMueve (Enemigo e);

/**
*   @brief Dibuja el Enemigo en pantalla.
*   Para dibujarlo, se utiliza la función Pantalla_DibujaImagen().
*   @code
*   EnemigoDibuja(e);
*   @endcode
*   @param e Variable perteneciente al Enemigo
*/
void EnemigoDibuja (Enemigo e);

/**
*   @brief Permite el choque entre el Enemigo y el Personaje.
*   Recoge las coordenadas de los dos y si coinciden es que chocan.
*   @code
*   EnemigoColision(e,p);
*   @endcode
*   @param e Variable perteneciente al Enemigo
*   @param p Variable perteneciente al Personaje
*   @return Coordenadas del choque entre Enemigo y Personaje
*/
int EnemigoColision(Enemigo e, Personaje p);

#endif
