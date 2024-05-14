/* 
 * File:   Pregunta01Examen01PunterosMultiples.h
 * Author: Ivan
 *
 * Created on 14 de mayo de 2024, 8:48
 */

#ifndef PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H
#define PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#define INCREMENTO 5

using namespace std;

void cargarPedidos(int **&, char **&, const char *);
char *leerCadena(ifstream &, int , char );
void aumentarEspacios(int **&, char **&, int &, int &);
void asignarFecha(int *&, int , int , int );
void ordenar(int **, char **);
void qSort(int **, char **, int , int );
void cambiar(int *, int *, char *, char *);
void pruebaDeCargaDePedidos(int **, char **, const char *); 
void imprimirEncabezado(ofstream &);
void imprimirLinea(ofstream &, int , char );

#endif /* PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H */

