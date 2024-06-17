/* 
 * File:   Tesoreria.h
 * Author: Ivan
 *
 * Created on 17 de junio de 2024, 17:18
 */

#ifndef TESORERIA_H
#define TESORERIA_H

#include "Arbol.h"

class Tesoreria {
private:
    class Arbol aboleta;
public:
    Tesoreria();
    virtual ~Tesoreria();
    void cargaalumnos();
    void imprimeboleta();
};

#endif /* TESORERIA_H */

