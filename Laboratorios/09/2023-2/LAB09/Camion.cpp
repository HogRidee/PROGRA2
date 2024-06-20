/* 
 * File:   Camion.cpp
 * Author: Ivan
 * 
 * Created on 20 de junio de 2024, 17:59
 */

#include "Camion.h"

Camion::Camion() {
    ejes = 0;
    llantas = 0;
}

Camion::~Camion() {
}

bool Camion::agregarPedido(int id, NPedido pedido) { // Implementación del método agregarPedido
    if (mdeposito.size() < 5) {
        mdeposito[id] = pedido;
        return true;
    }
    return false;
}

void Camion::eliminarPedido(int id) { // Implementación del método eliminarPedido
    mdeposito.erase(id);
}

void Camion::setLlantas(int llantas) {
    this->llantas = llantas;
}

int Camion::getLlantas() const {
    return llantas;
}

void Camion::setEjes(int ejes) {
    this->ejes = ejes;
}

int Camion::getEjes() const {
    return ejes;
}
