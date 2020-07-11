/**
*   @file Colision.h
*   @author Radoslaw Krzysztof Krolikowski
*   @date   04/2020
*   @brief  Fichero de Cabecera del TDA Colision.
*/


#ifndef __Colision_H__
#define _Colision_H__

/**
*   @brief Recoge los datos necesarios para ver si la colision se ha producido y donde
*   @param x1 Recoge la posición horizontal del primer objeto
*   @param y1 Recoge la posición vertical del primer objeto
*   @param w1 Recoge la Anchura del primer objeto
*   @param h1 Recoge la Altura del primer objeto
*   @param x2 Recoge la posición horizontal del segundo objeto
*   @param y2 Recoge la posición vertical del segundo objeto
*   @param w2 Recoge la Anchura del segundo objeto
*   @param h2 Recoge la Altura del segundo objeto
*   @return Si se ha producido el choque o no
*/
int Colision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);

#endif
