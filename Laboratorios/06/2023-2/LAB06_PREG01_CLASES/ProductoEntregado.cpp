/* 
 * File:   ProductoEntregado.cpp
 * Author: Ivan
 * 
 * Created on 22 de mayo de 2024, 16:13
 */

#include "ProductoEntregado.h"

ProductoEntregado::ProductoEntregado() {
    codigo = nullptr;
    precio = 0.0;
}

ProductoEntregado::~ProductoEntregado() {
    if(codigo) delete[] codigo;
}

void ProductoEntregado::SetPrecio(double precio) {
    this->precio = precio;
}

double ProductoEntregado::GetPrecio() const {
    return precio;
}

void ProductoEntregado::SetCodigo(char* codigo) {
    if(this->codigo) delete[] this->codigo;
    this->codigo = new char[strlen(codigo)+1];
    strcpy(this->codigo, codigo);
}

char* ProductoEntregado::GetCodigo() const {
    char *buffer = new char[strlen(codigo)+1];
    strcpy(buffer, codigo);
    return buffer;
}

