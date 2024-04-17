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

using namespace std;

void lecturaDeLibros (const char *, char ***&, int **&);
char *leerCadena(ifstream &, int , char );
void pruebaDeLecturaDeLibros (const char *, char ***, int **);

#endif /* METODOEXACTODEMEMORIA_H */

