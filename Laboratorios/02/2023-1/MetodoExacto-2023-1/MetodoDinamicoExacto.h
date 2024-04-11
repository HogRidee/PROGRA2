/* 
 * File:   MetodoDinamicoExacto.h
 * Author: ivana
 *
 * Created on 11 de abril de 2024, 06:15 PM
 */

#ifndef METODODINAMICOEXACTO_H
#define METODODINAMICOEXACTO_H

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void lecturaAlumnos(const char *, int *&, char **&, char *&, int *&, int *&);
void pruebaLecturaAlumnos(const char *, int *, char **, char *, int *, int *);
void leerAlumno(ifstream &, char *&, int *&, int *&);
char* leerCadenaExacta(ifstream &, int , char );
ifstream abrirArchivoLectura(const char *);

#endif /* METODODINAMICOEXACTO_H */

