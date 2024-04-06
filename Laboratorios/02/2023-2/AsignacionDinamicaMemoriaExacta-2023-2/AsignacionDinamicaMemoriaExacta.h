/* 
 * File:   AsignacionDinamicaMemoriaExacta.h
 * Author: Ivan
 *
 * Created on 6 de abril de 2024, 12:32
 */

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

void lecturaDeProductos(const char *, char ***&, int *&, double *&);
ifstream abrirArchivoLectura(const char *);
char* leerCadena(ifstream &, char );
void pruebaDeLecturaDeProductos(const char *, char ***, int *, double *);
ofstream abrirArchivoEscritura(const char *);
void imprimirLinea(char , int , ofstream &);

#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */

