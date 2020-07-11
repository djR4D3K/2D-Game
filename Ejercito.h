/**
*   @file Ejercito.h
*   @author Radoslaw Krzysztof Krolikowski
*   @date 06/2020
*   @brief  Fichero de Cabecera del TDA Ejercito
*/

#ifndef __Ejercito_H__
#define __Ejercito_H__
#include "Pantalla.h"
#include "Personaje.h"
#include "Enemigo.h"

/**
*   @brief Puntero a estructura Ejercito
*   Se empleará para manejar entidades de tipo Ejercito
*/
typedef struct EjercitoRep * Ejercito;

/**
*   @brief Crea una nueva variable Ejercito y devuelve un puntero hacía ella.
*   Se reserva memoria con la función malloc().
*   @code
*   Ejercito ejercito = EjercitoCrea(50);
*   @endcode
*   @param n Número de Enemigos que constituyen el Ejército
*   @return Puntero al nuevo Ejército creado.
*/
Ejercito EjercitoCrea(int n);

/**
*   @brief Libera memoria perteneciente al Ejército.
*   Al estar compuesto por Enemigos, se utilizan funciones del TDA Enemigo.
*   Se libera memoria con las funciones EnemigoLibera y free().
*   @code
*   EjercitoLibera (ejercito1);
*   @endcode
*   @param e1 Variable perteneciente al Ejercito que se desea liberar.
*/
void EjercitoLibera(Ejercito e1);

/**
*   @brief Inserta los Enemigos de los que está compuesto el Ejército.
*   Al estar compuesto por Enemigos, se utilizan funciones del TDA Enemigo.
*   @code
*   EjercitoInserta(ejercito1, enemigoImagen, rand()%(Pantalla_Anchura()-40), rand()%(Pantalla_Altura()-40), 80, 80, 50, 50);
*   @endcode
*   @param e1 Variable perteneciente al Ejército
*   @param i Imagen que representará al Ejército, en este caso el Enemigo
*   @param x Posición horizontal de los Enemigos del Ejército
*   @param y Posición vertical de los Enemigos del Ejército
*   @param w Anchura de los Enemigos del Ejército
*   @param h Altura de los Enemigos del Ejército
*   @param vx Velocidad de movimiento horizontal de cada Enemigo
*   @param vy Velocidad de movimiento vertical de cada Enemigo
*/
void EjercitoInserta (Ejercito e1, Imagen i, int x, int y, int w, int h, int vx, int vy);

/**
*   @brief Dibuja los Enemigos de los que está compuesto el Ejército en pantalla.
*   Al estar compuesto por Enemigos, se utilizan funciones del TDA Enemigo.
*   @code
*   EjercitoDibuja(ejercito1);
*   @endcode
*   @param e1 Variable perteneciente al Ejército
*/
void EjercitoDibuja (Ejercito e1);

/**
*   @brief Responsable del movimiento de los Enemigos de los que está compuesto el Ejército.
*   Al estar compuesto por Enemigos, se utilizan funciones del TDA Enemigo.
*   @code
*   EjercitoMueve(ejercito1);
*   @endcode
*   @param e1 Variable perteneciente al Ejército
*/
void EjercitoMueve(Ejercito e1);

/**
*   @brief Permite la colisión entre los Enemigos del Ejército y el Personaje.
*   Recoge las coordenadas de los dos y si coinciden, se produce el choque.
*   @code
*   EjercitoColision(ejercito1, personaje);
*   @endcode
*   @param e1 Variable perteneciente al Ejército
*   @param p Variable perteneciente al Personaje
*   @return Coordenadas del choque entre los Enemigos del Ejército y el Personaje.
*/
int EjercitoColision (Ejercito e1, Personaje p); //

#endif // __Ejercito_H__
