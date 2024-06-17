/* 
 * File:   Arbol.h
 * Author: Ivan
 *
 * Created on 17 de junio de 2024, 17:17
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
    class Nodo *raiz;
    class Escala lescala[10];
    void insertarR(class Nodo *&arbol, const class Boleta &dato);
public:
    Arbol();
    virtual ~Arbol();
    void crear();
};

#endif /* ARBOL_H */

