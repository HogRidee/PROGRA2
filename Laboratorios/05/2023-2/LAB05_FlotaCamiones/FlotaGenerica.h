/* 
 * File:   FlotaGenerica.h
 * Author: Ivan
 *
 * Created on 2 de mayo de 2024, 10:14
 */

#ifndef FLOTAGENERICA_H
#define FLOTAGENERICA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

#include "PilaConEnteros.h"
#include "PilaConRegistros.h"

void cargacamiones(void *&, int , double , void * (*leenumero)(ifstream&),
        int (*calculanumero) (void*),const char *);
void push(void *, void *&, int (*calculanumero)(void*), double, int &);
void muestracamiones(void *, int ,void (*imprimenumero)(void*),const char *);

#endif /* FLOTAGENERICA_H */

