/* 
 * File:   Tesoreria.h
 * Author: Ivan
 *
 * Created on 17 de junio de 2024, 13:21
 */

#ifndef TESORERIA_H
#define TESORERIA_H

#include "Arbol.h"

class Tesoreria {
private:
    Arbol aboleta;
public:
    void cargaalumnos();
    void actualizaboleta();
    void imprimeboleta();
};

#endif /* TESORERIA_H */

