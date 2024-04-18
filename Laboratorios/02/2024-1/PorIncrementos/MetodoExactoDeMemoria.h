/* 
 * File:   MetodoExactoDeMemoria.h
 * Author: Ivan
 *
 * Created on 17 de abril de 2024, 16:11
 */

#ifndef METODOEXACTODEMEMORIA_H
#define METODOEXACTODEMEMORIA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#define INCREMENTO 5

using namespace std;

void lecturaDeLibros (const char *, char ***&, int **&);
char *leerCadena(ifstream &, int , char );
void aumentarEspacios(char ***&, int **&, int &, int &);
void cargarLibros(char ***&, int **&, int , char *, char *, char *, int );
void pruebaDeLecturaDeLibros (const char *, char ***, int **);
void imprimirEncabezado(ofstream &);
void imprimirLinea(ofstream &, char , int );
void atencionDePedidos (const char *, char ***, int **&, int **&, char ***&, 
        bool **&);
void incrementarEspacio(char ***&, bool **&, int &, int &);
void cargarPedidos(ifstream &, char **&, bool *&, char ***, int **&);
void incrementarEspacio(char **&, bool *&, int &, int &);
void cargarCodigo(char *, char *&, bool &, char ***, int **&);
int buscarLibro(char ***, char *);

#endif /* METODOEXACTODEMEMORIA_H */

