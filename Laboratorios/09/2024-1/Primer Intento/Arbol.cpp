/* 
 * File:   Arbol.cpp
 * Author: Ivan
 * 
 * Created on 7 de julio de 2024, 13:24
 */

#include "Arbol.h"

Arbol::Arbol() {
    raiz = nullptr;
}

Arbol::~Arbol() {
    delete raiz;
}

