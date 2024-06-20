/* 
 * File:   NPedido.cpp
 * Author: Ivan
 * 
 * Created on 20 de junio de 2024, 17:49
 */

#include "NPedido.h"

NPedido::NPedido() {
    cantidad = 0;
    codigo = nullptr;
    peso = 0.0;
}

NPedido::~NPedido() {
    if(codigo) delete[] codigo;
}

void NPedido::SetPeso(double peso) {
    this->peso = peso;
}

double NPedido::GetPeso() const {
    return peso;
}

void NPedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int NPedido::GetCantidad() const {
    return cantidad;
}

void NPedido::SetCodigo(char* cad) {
    if(codigo) delete[] codigo;
    codigo = new char[strlen(cad)+1];
    strcpy(codigo, cad);
}

void NPedido::GetCodigo(char *cad) const {
    if(codigo == nullptr) cad[0] = 0;
    else strcpy(cad, codigo);
}

