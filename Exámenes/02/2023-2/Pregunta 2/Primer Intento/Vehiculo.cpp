/* 
 * File:   Vehiculo.cpp
 * Author: Ivan
 * 
 * Created on 4 de julio de 2024, 10:40
 */

#include "Vehiculo.h"
#include "Pedido.h"

Vehiculo::Vehiculo() {
    dni = 0;
    carga_actual = 0.0;
    carga_maxima = 0.0;
}

Vehiculo::~Vehiculo() {
}

void Vehiculo::SetCarga_actual(double carga_actual) {
    this->carga_actual = carga_actual;
}

double Vehiculo::GetCarga_actual() const {
    return carga_actual;
}

void Vehiculo::SetCarga_maxima(double carga_maxima) {
    this->carga_maxima = carga_maxima;
}

double Vehiculo::GetCarga_maxima() const {
    return carga_maxima;
}

void Vehiculo::SetPlaca(string placa) {
    this->placa = placa;
}

string Vehiculo::GetPlaca() const {
    return placa;
}

void Vehiculo::SetDni(int dni) {
    this->dni = dni;
}

int Vehiculo::GetDni() const {
    return dni;
}

void Vehiculo::leer(ifstream &arch){
    arch >> dni;
    arch.get();
    getline(arch, placa, ',');
    arch >> carga_maxima;
    arch.get();
}

Vehiculo * Vehiculo::clonar(){
    
}

void Vehiculo::mostrar(ofstream& arch){
    arch << left << setw(20) << "Codigo de cliente: " << GetDni() << endl;
    arch << left << setw(20) << "Placa: " << GetPlaca() << endl;
    arch << left << setw(20) << "Carga Maxima: " << GetCarga_maxima() << endl;
    arch << left << setw(20) << "Carga Actual: " << GetCarga_actual() << endl;
}

bool Vehiculo::insertar(class Pedido pedido){
    double peso = pedido.GetPeso();
    double cargaActual = GetCarga_actual();
    cargaActual += peso;
    if(cargaActual > GetCarga_maxima()) return false;
    return true;
}