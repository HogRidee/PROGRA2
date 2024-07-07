/* 
 * File:   Nodo.cpp
 * Author: Ivan
 * 
 * Created on 7 de julio de 2024, 10:44
 */

#include "Nodo.h"

Nodo::Nodo() {
    izq = nullptr;
    der = nullptr;
}

Nodo::Nodo(class Vehiculo* veh){
    unidad = veh;
    izq = nullptr;
    der = nullptr;
}

Nodo::~Nodo() {
    delete unidad;
}

