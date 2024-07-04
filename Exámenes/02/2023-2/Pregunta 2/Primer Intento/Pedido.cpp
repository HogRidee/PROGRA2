/* 
 * File:   Pedido.cpp
 * Author: Ivan
 * 
 * Created on 4 de julio de 2024, 10:30
 */

#include "Pedido.h"

Pedido::Pedido() {
    cantidad = 0;
    peso = 0.0;
}

Pedido::~Pedido() {
}

void Pedido::SetPeso(double peso) {
    this->peso = peso;
}

double Pedido::GetPeso() const {
    return peso;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetCodigo(string codigo) {
    this->codigo = codigo;
}

string Pedido::GetCodigo() const {
    return codigo;
}

