/* 
 * File:   Vehiculo.cpp
 * Author: Ivan
 * 
 * Created on 20 de junio de 2024, 17:54
 */

#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    actcarga = 0.0;
    cliente = 0;
    maxcarga = 0.0;
    placa = nullptr;
}

Vehiculo::~Vehiculo() {
    if(placa) delete[] placa;
}

void Vehiculo::SetActcarga(double actcarga) {
    this->actcarga = actcarga;
}

double Vehiculo::GetActcarga() const {
    return actcarga;
}

void Vehiculo::SetMaxcarga(double maxcarga) {
    this->maxcarga = maxcarga;
}

double Vehiculo::GetMaxcarga() const {
    return maxcarga;
}

void Vehiculo::SetPlaca(char* cad) {
    if(placa) delete[] placa;
    placa = new char[strlen(cad)+1];
    strcpy(placa, cad);
}

void Vehiculo::GetPlaca(char *cad) const {
    if(placa == nullptr) cad[0] = 0;
    else strcpy(cad, placa);
}

void Vehiculo::SetCliente(int cliente) {
    this->cliente = cliente;
}

int Vehiculo::GetCliente() const {
    return cliente;
}

