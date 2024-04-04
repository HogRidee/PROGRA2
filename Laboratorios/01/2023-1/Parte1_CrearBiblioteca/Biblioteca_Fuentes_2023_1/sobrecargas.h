/* 
 * File:   sobrecargas.h
 * Author: Ivan
 *
 * Created on 4 de abril de 2024, 10:48
 */

#ifndef SOBRECARGAS_H
#define SOBRECARGAS_H

#include <iostream>
#include <fstream>
#include <cstring>

#include "AperturaDeArchivos.h"
#include "sobrecargas.h"
#include "Estructuras.h"

using namespace std;

bool operator >> (istream &, StCurso &);
bool operator >> (istream &, StAlumno &);
bool operator >> (istream &, StRegistroDeMatricula &);
void operator += (StCurso *, const StCurso &);
void operator += (StAlumno *, const StAlumno &);
void operator *= (StCurso *, const StRegistroDeMatricula &);

#endif /* SOBRECARGAS_H */

