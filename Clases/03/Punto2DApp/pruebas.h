/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pruebas.h
 * Author: Ivan
 *
 * Created on 23 de marzo de 2024, 11:37
 */

#ifndef PRUEBAS_H
#define PRUEBAS_H

#include <iostream>
#include <fstream>
using namespace std;

struct Punto2D
{
    int x;
    int y;
};

Punto2D operator+(const Punto2D &p1, const Punto2D &p2);

void operator+=(Punto2D &p1, const Punto2D &p2);

ostream& operator<<(ostream &out,const Punto2D &p);

istream& operator >> (istream &in, Punto2D &p);

void operator++(Punto2D &p1);


#endif /* PRUEBAS_H */

