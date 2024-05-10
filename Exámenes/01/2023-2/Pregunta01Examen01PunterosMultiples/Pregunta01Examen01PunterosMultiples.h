/* 
 * File:   Pregunta01Examen01PunterosMultiples.h
 * Author: Ivan
 *
 * Created on 9 de mayo de 2024, 16:57
 */

#ifndef PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H
#define PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

#define INCREMENTO 5

using namespace std;

void cargarPedidos(int **&, char **&, const char *);
char *leerCadena(ifstream &, int , char );
int convertirFecha(int , int , int );
void aumentarEspacios(int **&, char **&, int &, int &);
void asignarFechaPedido(int *&, int , int , int );
void ordenarPedidos(int **, char **);
void mergeSort(int **, char **, int , int );
void merge(int **, char **, int , int , int );
void copiarArreglos(int **, char **, int , int , int , int , int **, int **, 
        char **, char **);
void fusionarArreglos(int **, char **, int , int , int , int **, int **, char **, 
        char **);
void fusionarMientrasAmbos(int **, char **, int &, int &, int &, int , int , 
        int **, int **, char **, char **);
void fusionarRestanteIzq(int **, char **, int &, int &, int , int **, char **);
void fusionarRestanteDer(int **, char **, int &, int &, int , int **, char **);
void liberarMemoria(int **, int **, char **, char **);
void pruebaDeCargaDePedidos(int **, char **, const char *);
void imprimirCabeceraCargaPedidos(ofstream &);
void imprimirLinea(ofstream &, int , char );

#endif /* PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H */

