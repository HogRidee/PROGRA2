/* 
 * File:   funciones.h
 * Author: Ivan
 *
 * Created on 23 de marzo de 2024, 13:43
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Estructuras.h"
#include "AperturaDeArchivos.h"

using namespace std;

bool operator >> (istream &, Cliente &);
bool operator >> (istream &, Producto &);

#endif /* FUNCIONES_H */

