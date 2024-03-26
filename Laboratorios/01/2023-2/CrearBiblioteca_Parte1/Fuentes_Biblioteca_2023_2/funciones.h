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

#define NCLIENTES 150
#define NPRODUCTOS 200

#include "Estructuras.h"
#include "AperturaDeArchivos.h"

using namespace std;

bool operator >> (istream &, Cliente &);
bool operator >> (istream &, Producto &);
bool operator >> (istream &in, Pedido &);
void leerCodigoProducto (istream &, Producto &);
void operator += (Cliente *, const Pedido &);
int buscarCliente(Cliente *, int );
bool operator += (Producto *, Pedido );
int buscarCodigo(Producto *, const Pedido &);

#endif /* FUNCIONES_H */

