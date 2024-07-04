/* 
 * File:   Furgon.cpp
 * Author: Ivan
 * 
 * Created on 4 de julio de 2024, 10:55
 */

#include "Furgon.h"

Furgon::Furgon() {
    filas = 0;
    puertas = 0;
}

Furgon::~Furgon() {
}

void Furgon::SetPuertas(int puertas) {
    this->puertas = puertas;
}

int Furgon::GetPuertas() const {
    return puertas;
}

void Furgon::SetFilas(int filas) {
    this->filas = filas;
}

int Furgon::GetFilas() const {
    return filas;
}

void Furgon::leer(ifstream &arch){
    Vehiculo::leer(arch);
    arch >> filas;
    arch.get();
    arch >> puertas;
    arch.get();
}

