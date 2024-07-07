/* 
 * File:   Nodo.h
 * Author: Ivan
 *
 * Created on 7 de julio de 2024, 10:44
 */

#ifndef NODO_H
#define NODO_H

#include "Vehiculo.h"
#include "Arbol.h"

class Nodo {
private:
    class Vehiculo *unidad;
    class Nodo *izq;
    class Nodo *der;
public:
    Nodo();
    Nodo(class Vehiculo *veh);
    virtual ~Nodo();
    
    friend class Arbol;
};

#endif /* NODO_H */

