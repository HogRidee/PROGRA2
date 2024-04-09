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
char** leerProducto(ifstream &);
char* leerCadenaExacta(ifstream &, int , char );
void pruebaDeLecturaDeProductos(const char *, char ***, int *, double *);
ofstream abrirArchivoEscritura(const char *);
void imprimirLinea(char , int , ofstream &);
void lecturaDePedidos(const char *, int *&, char ***&, int ***&);
int buscarFecha(int *, int , int &);
void agregarFecha(int ***, char ***, int *, int , int *, int &, int &);
void agregarPedido(char **, int **, int &, int , int , char *);
void cargarArreglos(int *&, char ***&, int ***&, int *, char ***, int ***, 
        int *, int n);
void cargarInterno(char **&, int **&, char **, int **, int );
void pruebaDeLecturaDePedidos(const char *, int *, char ***, int ***);
void reporteDeEnvioDePedidos(const char* , char ***, int *&, double *, int *, 
        char ***, int ***);
void imprimirProductos(char **, int **, char ***, double *, int *&, ofstream &);
int buscarProducto(char ***, char *);
void imprimirFecha(int , ofstream &);

#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */

