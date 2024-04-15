/* 
 * File:   AsignacionDinamicaMemoriaExacta.h
 * Author: Ivan
 *
 * Created on 15 de abril de 2024, 16:57
 */

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#define INCREMENTO 5

using namespace std;

void lecturaDeProductos (const char *, char ***&, int *&, double *&);
void aumentarEspacios(double *&, int & , int );
void aumentarEspacios(int *&, int &, int );
char *leerCadena(ifstream &, char);
ifstream abrirArchivoLectura(const char *);
void pruebaDeLecturaDeProductos (const char *, char ***, int *, double *);

#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */

