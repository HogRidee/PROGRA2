/* 
 * File:   Arbol.cpp
 * Author: Ivan
 * 
 * Created on 7 de julio de 2024, 10:48
 */

#include "Arbol.h"

Arbol::Arbol() {
    raiz = nullptr;
}

Arbol::~Arbol() {
}

void Arbol::insertar(class Vehiculo* veh){
    raiz = insertarRecursivo(raiz, veh);
}

Nodo* Arbol::insertarRecursivo(class Nodo* nodo, class Vehiculo* veh){
    if(nodo == nullptr) return new class Nodo(veh);
    if(veh->GetDni() < nodo->unidad->GetDni())
        nodo->izq = insertarRecursivo(nodo->izq, veh);
    else
        nodo->der = insertarRecursivo(nodo->der, veh);
    return nodo;
}

void Arbol::imprimirArbol(ofstream& arch){
    arch << right << setw(50) << "REPORTE DE FLOTA ORDENADA POR DNI" << endl;
    imprimirLinea(arch, 100, '=');
    inOrden(arch, raiz);
}

void Arbol::inOrden(ofstream &arch, class Nodo *nodo){
    if(nodo != nullptr){
        inOrden(arch, nodo->izq);
        nodo->unidad->mostrar(arch);
        imprimirLinea(arch, 100, '-');
        inOrden(arch, nodo->der);
    }
}

void Arbol::eliminarNodosHoja(int& cantidad){
    eliminarNodosHojaRecursivo(raiz, cantidad);
}

bool Arbol::eliminarNodosHojaRecursivo(class Nodo* nodo, int& cantidad){
    if(nodo == nullptr) return false;
    if(nodo->izq == nullptr and nodo->der == nullptr and cantidad > 0){
        delete nodo;
        nodo = nullptr;
        cantidad--;
        return true;
    }
    return eliminarNodosHojaRecursivo(nodo->izq, cantidad) or 
            eliminarNodosHojaRecursivo(nodo->der, cantidad);
}