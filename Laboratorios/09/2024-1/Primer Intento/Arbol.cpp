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

void Arbol::insertar(class NEstante* estante) {
    raiz = insertar(raiz, estante);
}

NEstante* Arbol::insertar(class NEstante* raiz, class NEstante* estante) {
    if(raiz == nullptr) return estante;
    if(estante->GetDisponible() < raiz->GetDisponible())
        raiz->izq = insertar(raiz->izq, estante);
    else
        raiz->der = insertar(raiz->der, estante);
    return raiz;
}

void Arbol::imprimir(ofstream& arch) {
    imprimirInOrden(raiz, arch);
}

void Arbol::imprimirInOrden(class NEstante* nodo, ofstream& arch) {
    if(nodo != nullptr){
        imprimirInOrden(nodo->izq, arch);
        nodo->imprimirEstante(arch);
        imprimirInOrden(nodo->der, arch);
    }
}



