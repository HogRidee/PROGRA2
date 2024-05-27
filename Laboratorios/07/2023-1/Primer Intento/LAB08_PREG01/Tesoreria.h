/* 
 * File:   Tesoreria.h
 * Author: Ivan
 *
 * Created on 26 de mayo de 2024, 18:07
 */

#ifndef TESORERIA_H
#define TESORERIA_H

#include "Presencial.h" 
#include "Semipresencial.h"
#include "Virtual.h"
#include "Escala.h"

class Tesoreria {
private:
    Presencial lpresencial[100];
    Semipresencial lsemipresencial[100];
    Virtual lvirtual[100];
    Escala lescala[10];
public:
    Tesoreria();
    Tesoreria(const Tesoreria& orig);
    virtual ~Tesoreria();
    void cargaescalas();
    void cargaalumnos();
};

#endif /* TESORERIA_H */

