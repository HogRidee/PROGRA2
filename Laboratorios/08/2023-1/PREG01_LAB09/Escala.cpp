/* 
 * File:   Escala.cpp
 * Author: Ivan
 * 
 * Created on 3 de junio de 2024, 13:28
 */

#include "Escala.h"

Escala::Escala() {
    codigo = 0;
    precio = 0.0;
}

Escala::Escala(const Escala& orig) {
}

Escala::~Escala() {
}

void Escala::SetPrecio(double precio) {
    this->precio = precio;
}

double Escala::GetPrecio() const {
    return precio;
}

void Escala::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Escala::GetCodigo() const {
    return codigo;
}



