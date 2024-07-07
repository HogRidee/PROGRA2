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
public:
    Arbol();
    virtual ~Arbol();
};

#endif /* ARBOL_H */

