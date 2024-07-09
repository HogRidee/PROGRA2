/* 
 * File:   Pedido.cpp
 * Author: Ivan
 * 
 * Created on 9 de julio de 2024, 8:15
 */

#include "Pedido.h"

Pedido::Pedido() {
    cantidad = 0;
    peso = 0.0;
}

Pedido::Pedido(const Pedido& orig) {
    (*this) = orig;
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

void Pedido::leerPedido(ifstream& arch) {
    getline(arch, codigo, ',');
    arch >> cantidad;
    arch.get();
    arch >> peso;
    arch.get();
}

void Pedido::mostrarPedido(ofstream& arch) {
    arch << left << setw(10) << codigo;
    arch << left << setw(8) << peso;
    arch << left << setw(5) << cantidad << endl;
}

void Pedido::operator=(const Pedido& ped) {
    cantidad = ped.GetCantidad();
    codigo = ped.GetCodigo();
    peso = ped.GetPeso();
}
