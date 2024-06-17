/* 
 * File:   Presencial.cpp
 * Author: Ivan
 * 
 * Created on 17 de junio de 2024, 17:08
 */

#include "Presencial.h"

Presencial::Presencial() {
    recargo = 0.0;
    total = 0.0;
}

Presencial::~Presencial() {
}

void Presencial::SetTotal(double total) {
    this->total = total;
}

double Presencial::GetTotal() const {
    return total;
}

void Presencial::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double Presencial::GetRecargo() const {
    return recargo;
}
    
void Presencial::lee(ifstream &file){
    Alumno::lee(file);
    file >> recargo;
    file.get();
}

