/* 
 * File:   Biblioteca.h
 * Author: Ivan
 *
 * Created on 7 de julio de 2024, 13:25
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <fstream>
#include <iostream>

#include "Arbol.h"

using namespace std;

class Biblioteca {
private:
    class Arbol AEstante;
public:
    Biblioteca();
    virtual ~Biblioteca();
    
    void carga();
    void muestra();
    void prueba(int n);
};

#endif /* BIBLIOTECA_H */

