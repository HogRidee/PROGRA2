/* 
 * File:   Furgon.cpp
 * Author: Ivan
 * 
 * Created on 9 de julio de 2024, 8:19
 */

#include <algorithm>

#include "Furgon.h"

Furgon::Furgon() {
    filas = 0;
    puertas = 0;
}

Furgon::Furgon(const Furgon& orig) {
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

void Furgon::leer(ifstream& arch) {
    Vehiculos::leer(arch);
    arch >> filas;
    arch.get();
    arch >> puertas;
    arch.get();
}

void Furgon::mostrar(ofstream& arch) {
    Vehiculos::mostrar(arch);
    arch << left << setw(20) << "#Puertas" << puertas << endl;
    arch << left << setw(20) << "#Filas" << filas << endl;
    arch << left << setw(20) << "Lista de Pedidos: " << endl;
    if(depositos.empty()) arch << "No hay pedidos para el cliente" << endl;
    else{
        for(Pedido pedido: depositos){
            pedido.mostrarPedido(arch);
        }
    }
}

bool Furgon::insertar(Pedido pedido) {
    if(not Vehiculos::insertar(pedido)) return false;
    //inserta ordenado por peso
    auto pos = find_if(depositos.begin(), depositos.end(), [&](const Pedido& p){
       return pedido.GetPeso() < p.GetPeso(); 
    });
    depositos.insert(pos, pedido);
    SetCarga_actual(GetCarga_actual() + pedido.GetPeso());
    return true;
}
