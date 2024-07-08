/* 
 * File:   Arbol.h
 * Author: Ivan
 *
 * Created on 7 de julio de 2024, 13:24
 */

#ifndef ARBOL_H
#define ARBOL_H

#include "NEstante.h"

class Arbol {
private:
    class NEstante *raiz;
    NEstante *insertar(class NEstante *raiz, class NEstante *estante);
    void imprimirInOrden(class NEstante *nodo, ofstream &arch);
public:
    Arbol();
    virtual ~Arbol();
    
    void insertar(class NEstante *estante);
    void imprimir(ofstream &arch);
};

#endif /* ARBOL_H */

