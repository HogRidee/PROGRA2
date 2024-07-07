/* 
 * File:   Furgon.cpp
 * Author: Ivan
 * 
 * Created on 7 de julio de 2024, 9:45
 */

#include "Furgon.h"

Furgon::Furgon() {
}

Furgon::~Furgon() {
}

void Furgon::SetPuertas(int puertas) {
    this->puertas = puertas;
}

int Furgon::GetPuertas() const {
    return puertas;
}

void Furgon::SetFilas(int filas) {
    this->filas = filas;
}

int Furgon::GetFilas() const {
    return filas;
}

void Furgon::leer(ifstream& arch){
    Vehiculo::leer(arch);
    arch >> filas;
    arch.get();
    arch >> puertas;
    arch.get();
}

void Furgon::mostrar(ofstream& arch){
    Vehiculo::mostrar(arch);
    arch << left << setw(20) << "Puertas: " << puertas << endl;
    arch << left << setw(20) << "Filas: " << filas << endl;
    arch << "Lista de Pedidos: " << endl;
    if(depositos.empty()) arch << "No hay pedidos para el cliente" << endl;
    else{
        for(Pedido x: depositos)
            x.mostrarPedido(arch);
    }
}

bool Furgon::insertar(class Pedido pedido){
    if(not Vehiculo::insertar(pedido)) return false;
    depositos.push_back(pedido);
    SetCarga_actual(GetCarga_actual() + pedido.GetPeso());
    depositos.sort([](const class Pedido &a, const class Pedido &b){
        return a.GetPeso() < b.GetPeso();
    });
    return true;
}