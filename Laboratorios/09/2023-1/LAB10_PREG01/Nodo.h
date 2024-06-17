/* 
 * File:   Nodo.h
 * Author: Ivan
 *
 * Created on 17 de junio de 2024, 13:09
 */

#ifndef NODO_H
#define NODO_H

#include "Nodo.h"
#include "Boleta.h"

class Nodo {
private:
    Boleta dboleta;
    Nodo *izq;
    Nodo *der;
public:
    Nodo();
    friend class Arbol;
};

#endif /* NODO_H */

