/* 
 * File:   Arbol.h
 * Author: Ivan
 *
 * Created on 7 de julio de 2024, 10:48
 */

#ifndef ARBOL_H
#define ARBOL_H

#include "Nodo.h"
#include "Vehiculo.h"
#include "Util.h"

class Arbol {
private:
    class Nodo *raiz;
    
    Nodo *insertarRecursivo(class Nodo *nodo, class Vehiculo *veh);
    void inOrden(ofstream &arch, class Nodo *nodo);
    bool eliminarNodosHojaRecursivo(class Nodo *nodo, int &cantidad);
public:
    Arbol();
    virtual ~Arbol();
    
    void insertar(class Vehiculo *veh);
    void imprimirArbol(ofstream &arch);
    void eliminarNodosHoja(int &cantidad);
};

#endif /* ARBOL_H */

