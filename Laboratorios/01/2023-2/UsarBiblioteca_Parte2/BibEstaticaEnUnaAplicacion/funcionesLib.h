/* 
 * File:   funcionesLib.h
 * Author: Ivan
 *
 * Created on 27 de marzo de 2024, 15:11
 */

#ifndef FUNCIONESLIB_H
#define FUNCIONESLIB_H

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
bool operator += (Producto *, Pedido &);
int buscarCodigoPedido(Producto *, const Pedido &);
ostream& operator<<(ostream &,const Cliente &);
ostream& operator << (ostream &, const Producto &);
void imprimirCabeceraProducto(ostream &, const Producto &);

#endif /* FUNCIONESLIB_H */

