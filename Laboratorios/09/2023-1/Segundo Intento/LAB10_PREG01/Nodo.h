/* 
 * File:   Nodo.h
 * Author: Ivan
 *
 * Created on 17 de junio de 2024, 17:15
 */

#ifndef NODO_H
#define NODO_H

#include "Nodo.h"
#include "Boleta.h"

class Nodo {
private:
    class Boleta dboleta;
    class Nodo *izq;
    class Nodo *der;
public:
    Nodo();
    friend class Arbol;
};

#endif /* NODO_H */

