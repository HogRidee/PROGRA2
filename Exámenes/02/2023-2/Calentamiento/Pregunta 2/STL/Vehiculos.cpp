/* 
 * File:   Vehiculos.cpp
 * Author: Ivan
 * 
 * Created on 9 de julio de 2024, 8:16
 */

#include "Vehiculos.h"
#include "Pedido.h"

Vehiculos::Vehiculos() {
    dni = 0;
    carga_actual = 0.0;
    carga_maxima = 0.0;
}

Vehiculos::Vehiculos(const Vehiculos& orig) {
}

Vehiculos::~Vehiculos() {
}

void Vehiculos::SetCarga_actual(double carga_actual) {
    this->carga_actual = carga_actual;
}

double Vehiculos::GetCarga_actual() const {
    return carga_actual;
}

void Vehiculos::SetCarga_maxima(double carga_maxima) {
    this->carga_maxima = carga_maxima;
}

double Vehiculos::GetCarga_maxima() const {
    return carga_maxima;
}

void Vehiculos::SetPlaca(string placa) {
    this->placa = placa;
}

string Vehiculos::GetPlaca() const {
    return placa;
}

void Vehiculos::SetDni(int dni) {
    this->dni = dni;
}

int Vehiculos::GetDni() const {
    return dni;
}

void Vehiculos::leer(ifstream& arch) {
    arch >> dni;
    arch.get();
    getline(arch, placa, ',');
    arch >> carga_maxima;
    arch.get();
}

void Vehiculos::mostrar(ofstream& arch) {
    arch << left << setw(20) << "Codigo de Cliente: " << dni << endl;
    arch << left << setw(20) << "Placa: " << placa << endl;
    arch << left << setw(20) << "Carga Maxima: " << carga_maxima << endl;
    arch << left << setw(20) << "Carga Actual: " << carga_actual << endl;
}

bool Vehiculos::insertar(class Pedido pedido) {
    if(carga_actual + pedido.GetPeso() > carga_maxima) return false;
    return true;
}

