
#ifndef METODOINCREMENTODEMEMORIA_H
#define METODOINCREMENTODEMEMORIA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

void lecturaDeLibros(const char*archLib,char ***&libros,int **&stock);
char *leerCadenaExacta(ifstream &arch);
void aumentarEspacio(char ***&libros,int **&stock,int &cap,int &n);
void asignarValores(char ***&libros,int **&stock,char *codigo,char *nombre,char *autor,int stockVar,int n);
void pruebaDeLecturaDeLibros(const char*archRep,char ***libros,int **stock);

void atencionDePedidos(const char*archPed,char ***libros,int **&stock,int **&pedidosClientes,char ***&pedidosLibros,bool **&pedidosAtendidos);
char *leerCadenaExactaVersion2(ifstream &arch);
int buscaDni(int dni,int **pedidosClientes,int n);
char *leerCadenaExactaVersion2(ifstream &arch);
void aumentarEspacioVersion2(int **&pedidosClientes,int &n,int &cap);
void agregarPedido(int *&pedidosClientes,int pedidos,int dni,int &n,int &cap);
void aumentarEspacioInterno(int *&pedidosClientes,int dni,int &n,int &cap);
void aumentarEspacioLibros(char ***&pedidosLibros,bool **&pedidosAtendidos,int &n,int &cap);
void agregarLibros(char **&pedidosLibros,bool*&pedidosAtendidos,char *codigoLibro,char ***libros,int **&stock,int &n,int &cap);
void aumentarEspacioInternoLibro(char **&pedidosLibros,bool *&pedidosAtendidos,int &n,int &cap);
void colocarAtendido(bool *&pedidosAtendidos,char *codigoLibro,char ***libros,int **&stock,int n);
int buscaCodigo(char *codigoLibro,char ***libros);
#endif /* METODOINCREMENTODEMEMORIA_H */

