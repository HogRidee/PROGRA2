/* 
 * File:   Camion.cpp
 * Author: Ivan
 * 
 * Created on 6 de julio de 2024, 13:43
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

void Camion::leer(ifstream& arch){
    Vehiculo::leer(arch);
    arch >> ejes;
    arch.get();
    arch >> llantas;
    arch.get();
}

void Camion::mostrar(ofstream& arch){
    Vehiculo::mostrar(arch);
    arch << left << setw(20) << "#Llantas: " << llantas << endl;
    arch << left << setw(20) << "#Ejes: " << ejes << endl;
    arch << left << setw(20) << "Lista de Pedidos: " << endl;
    if(depositos.size() == 0) arch << "No hay pedidos para el cliente" << endl;
    else{
        for(int i = 0; i < depositos.size(); i++){
            depositos[i].mostrarPedido(arch);
        }
    }
}

bool Camion::insertar(class Pedido pedido){
    if(not Vehiculo::insertar(pedido)) return false;
    if(depositos.size() < 5){
        depositos.push_back(pedido);
        double cargaActual = GetCarga_actual();
        double peso = pedido.GetPeso();
        cout << peso << endl;
    }
    return true;
}