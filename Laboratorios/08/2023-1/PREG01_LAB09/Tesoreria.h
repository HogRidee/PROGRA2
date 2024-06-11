/* 
 * File:   Tesoreria.h
 * Author: Ivan
 *
 * Created on 11 de junio de 2024, 17:15
 */

#ifndef TESORERIA_H
#define TESORERIA_H

#include "Boleta.h"
#include "Escala.h"

class Tesoreria {
private:
    class Boleta lboleta[100];
    class Escala lescala[10];
public:
    Tesoreria();
    Tesoreria(const Tesoreria& orig);
    virtual ~Tesoreria();
    void cargaescalas();
    void cargaalumnos();
    void cargaactualizaboleta();
    void imprimeboleta();
};

#endif /* TESORERIA_H */

