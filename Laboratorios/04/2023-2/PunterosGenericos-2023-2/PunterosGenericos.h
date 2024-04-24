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
int buscarCliente(int , void *);
void cargarPedido(void *&, char* , void *, int , int &);
int buscarProducto(char *,void *);
bool seEncontroProducto(void *,char *);
void atendemosPedidoProd(void *&,char *,int ,void *,int &);
void asignarPedido(char *,int ,int ,void *,int );
void *colocarPedido(char *,int ,int );
void pasarAmemExactaPedidos(void *,int );
void *pedidosExactos(void *,int );

#endif /* PUNTEROSGENERICOS_H */

