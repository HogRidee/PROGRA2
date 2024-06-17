/* 
 * File:   Arbol.h
 * Author: Ivan
 *
 * Created on 17 de junio de 2024, 13:12
 */

#ifndef ARBOL_H
#define ARBOL_H

#include "Nodo.h"
#include "Escala.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

#include "Boleta.h"

class Arbol {
private:
    Nodo *raiz;
    Escala lescala[10];
    
    void insertarR(class Nodo *&arbol, const class Boleta &dato);
    void mostrarEnOrdenR(ofstream &file, class Nodo *arbol);
public:
    Arbol();
    virtual ~Arbol();
    void crear();
    void mostrarEnOrden();
};

#endif /* ARBOL_H */

