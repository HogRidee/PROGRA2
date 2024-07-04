/* 
 * File:   Camion.cpp
 * Author: Ivan
 * 
 * Created on 4 de julio de 2024, 10:42
 */

#include "Camion.h"

Camion::Camion() {
    ejes = 0;
    llantas = 0;
}

Camion::~Camion() {
}

void Camion::SetLlantas(int llantas) {
    this->llantas = llantas;
}

int Camion::GetLlantas() const {
    return llantas;
}

void Camion::SetEjes(int ejes) {
    this->ejes = ejes;
}

int Camion::GetEjes() const {
    return ejes;
}

void Camion::leer(ifstream &arch){
    Vehiculo::leer(arch);
    arch >> ejes;
    arch.get();
    arch >> llantas;
    arch.get();
}