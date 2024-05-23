/* 
 * File:   Cliente.cpp
 * Author: Ivan
 * 
 * Created on 22 de mayo de 2024, 16:25
 */

#include "Cliente.h"

Cliente::Cliente() {
    dni = 0;
    nombre = nullptr;
    telefono = 0;
    cantidadProductosEntregados = 0;
    montoTotal = 0.0;
}

Cliente::~Cliente() {
    if(nombre) delete[] nombre;
}

void Cliente::SetMontoTotal(double montoTotal) {
    this->montoTotal = montoTotal;
}

double Cliente::GetMontoTotal() const {
    return montoTotal;
}

void Cliente::SetCantidadProductosEntregados(int cantidadProductosEntregados) {
    this->cantidadProductosEntregados = cantidadProductosEntregados;
}

int Cliente::GetCantidadProductosEntregados() const {
    return cantidadProductosEntregados;
}

void Cliente::SetProductosEntregados(ProductoEntregado producto) {
    this->productosEntregados[cantidadProductosEntregados] = producto;
    cantidadProductosEntregados++;
}

//ProductoEntregado* Cliente::GetProductosEntregados() const{
//    return productosEntregados;
//}

void Cliente::SetTelefono(int telefono) {
    this->telefono = telefono;
}

int Cliente::GetTelefono() const {
    return telefono;
}

void Cliente::SetNombre(char* nombre) {
    char *buffer = new char[strlen(nombre)+1];
    strcpy(buffer, nombre);
    this->nombre = buffer;
}

char* Cliente::GetNombre() const {
    char *buffer = new char[strlen(nombre)+1];
    strcpy(buffer, nombre);
    return buffer;
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

