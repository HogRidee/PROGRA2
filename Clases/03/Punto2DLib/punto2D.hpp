/* 
 * File  :   punto2D.hpp
 * Autor :   Ivan Alexander Araoz Andrade
 * Codigo:   20201216
 *
 * Creado el 22 de marzo de 2024, 04:24 PM
 */

#ifndef PUNTO2D_HPP
#define PUNTO2D_HPP

#include <iostream>
#include <fstream>
using namespace std;

struct Punto2D
{
    int x;
    int y;
};

Punto2D operator+(const Punto2D &, const Punto2D &);

void operator+=(Punto2D &, const Punto2D &);

ostream& operator<<(ostream &,const Punto2D &);

istream& operator >> (istream &, Punto2D &);

void operator++(Punto2D &);

#endif /* PUNTO2D_HPP */

