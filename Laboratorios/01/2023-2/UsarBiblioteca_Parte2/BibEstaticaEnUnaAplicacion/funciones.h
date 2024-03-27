/* 
 * File:   funciones.h
 * Author: Ivan
 *
 * Created on 27 de marzo de 2024, 15:32
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "funcionesLib.h"

void inicializarClientes(Cliente *&);
void inicializarProductos(Producto *&);
void procesarPedidos(Cliente *&arrClientes, Producto *&arrProductos);
void imprimirReporte(const Cliente *, const Producto *);
void imprimirLinea(char , int , ofstream &);
#endif /* FUNCIONES_H */

