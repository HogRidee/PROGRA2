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

#define INCREMENTO 5

using namespace std;

void cargarProductos(void *&, const char*);
void *leerProducto(ifstream &);
char *leerCadena(ifstream &, int , int );
void pruebaDeCargaDeProductos(void *);

#endif /* PREGUNTA02EXAMEN01PUNTEROSGENERICOS_H */

