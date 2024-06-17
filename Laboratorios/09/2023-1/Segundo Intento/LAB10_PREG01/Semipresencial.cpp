/* 
 * File:   Semipresencial.cpp
 * Author: Ivan
 * 
 * Created on 17 de junio de 2024, 17:09
 */

#include "Semipresencial.h"

Semipresencial::Semipresencial() {
    descuento = 0.0;
    total = 0.0;
}

Semipresencial::~Semipresencial() {
}

void Semipresencial::SetTotal(double total) {
    this->total = total;
}

double Semipresencial::GetTotal() const {
    return total;
}

void Semipresencial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Semipresencial::GetDescuento() const {
    return descuento;
}
 
void Semipresencial::lee(ifstream &file){
    Alumno::lee(file);
    file >> descuento;
    file.get();
}
