/* 
 * File:   Pregunta02Examen01PunterosGenericos.h
 * Author: Ivan
 *
 * Created on 9 de mayo de 2024, 18:50
 */

#ifndef PREGUNTA02EXAMEN01PUNTEROSGENERICOS_H
#define PREGUNTA02EXAMEN01PUNTEROSGENERICOS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;

void cargarProductos(void *&, const char*);
void *leerProducto(ifstream &, char *);
char *leerCadena(ifstream &, int , char );
int comparaCodigo(const void *, const void *);
void pruebaDeCargaDeProductos(void *);
void imprimirCabecera(ofstream &file);
void imprimirLinea(ofstream &, int , char );

#endif /* PREGUNTA02EXAMEN01PUNTEROSGENERICOS_H */

