/* 
 * File:   Camion.cpp
 * Author: Ivan
 * 
 * Created on 9 de julio de 2024, 8:17
 */

#include "Camion.h"

Camion::Camion() {
    ejes = 0;
    llantas = 0;
}

Camion::Camion(const Camion& orig) {
}

Camion::~Camion() {
}

void Camion::SetLlantas(int llantas) {
    this->llantas = llantas;
}

int Camion::GetLlantas() const {
    return llantas;
}

void Camion::SetEjes(int ejes) {
    this->ejes = ejes;
}

int Camion::GetEjes() const {
    return ejes;
}

void Camion::leer(ifstream& arch) {
    Vehiculos::leer(arch);
    arch >> ejes;
    arch.get();
    arch >> llantas;
    arch.get();
}

void Camion::mostrar(ofstream& arch) {
    Vehiculos::mostrar(arch);
    arch << left << setw(20) << "#Llantas" << llantas << endl;
    arch << left << setw(20) << "#Ejes" << ejes << endl;
    arch << left << setw(20) << "Lista de Pedidos: " << endl;
    if(depositos.size() == 0) arch << "No hay pedidos para el cliente" << endl;
    else{
        for(int i = 0; i < depositos.size(); i++){
            depositos[i].mostrarPedido(arch);
        }
    }
}

bool Camion::insertar(Pedido pedido) {
    if(not Vehiculos::insertar(pedido)) return false;
    if(depositos.size() < 5){
        depositos.push_back(pedido);
        SetCarga_actual(GetCarga_actual() + pedido.GetPeso());
    }
    return true;
}
