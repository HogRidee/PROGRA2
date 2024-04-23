/* 
 * File:   PunterosGenericos.h
 * Author: Ivan
 *
 * Created on 20 de abril de 2024, 18:24
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

void cargaproductos(void *&);
void *leerProducto(ifstream &);
char *leerCadenaExacta(ifstream &, int, char);
void cargaclientes(void *&);
void *leerCliente(ifstream &);
void cargapedidos(void *&, void *&);
bool verificarSiConsumeCredito(char *, void *&);

#endif /* PUNTEROSGENERICOS_H */

