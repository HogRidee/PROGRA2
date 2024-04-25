/* 
 * File:   PunterosGenericos.h
 * Author: Ivan
 *
 * Created on 25 de abril de 2024, 9:46
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

void cargaproductos(void *&);
char *leerCadena(ifstream &, int, char );
void *leerProducto(ifstream &, char *);
void cargaclientes(void *&);
void *leerCliente(ifstream &, int );
void cargapedidos(void *, void *&);
int buscarCliente(void *, int );
void cargarPedido(void *&, int &, char *, int , void *);
int buscarProducto(void *, char *);
void cargarProducto(void *&, int &, int , void *, char *);
void asignarPedido(void *& , int , char *, int , double );
void *colocarPedido(char *, int , double );
void pasarMemoriaExacta(void *&, int );
void *pedidosExactos(void *&, int );
void imprimereporte(void *);
void imprimirLinea(ofstream &, int , char );
void imprimirCabecera(ofstream &, void *);
void imprimirPedidos(ofstream &, void *);
void imprimirPedido(ofstream &, void *);
void imprimirContenidoPedido(ofstream &file, void *pedido);

#endif /* PUNTEROSGENERICOS_H */

