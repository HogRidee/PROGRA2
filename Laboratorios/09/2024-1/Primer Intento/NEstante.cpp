/* 
 * File:   NEstante.cpp
 * Author: Ivan
 * 
 * Created on 7 de julio de 2024, 13:20
 */

#include "NEstante.h"

NEstante::NEstante() {
    capacidad = 0.0;
    der = nullptr;
    disponible = 0.0;
    id = 0;
    izq = nullptr;
}

NEstante::~NEstante() {
    delete der;
    delete izq;
}

void NEstante::SetDisponible(double disponible) {
    this->disponible = disponible;
}

double NEstante::GetDisponible() const {
    return disponible;
}

void NEstante::SetCapacidad(double capacidad) {
    this->capacidad = capacidad;
    disponible = capacidad;
}

double NEstante::GetCapacidad() const {
    return capacidad;
}

void NEstante::SetId(int id) {
    this->id = id;
}

int NEstante::GetId() const {
    return id;
}

void NEstante::cargarLibros(ifstream &arch){
    char tipo;
    class NLibro libro;
    for(int i = 0; i < 10; i++){
        arch >> tipo;
        if(arch.eof()) break;
        arch.get();
        libro.asignarMemoria(tipo);
        disponible -= libro.leerLibro(arch);
        vlibros.push_back(libro);
    }
}

void NEstante::imprimirEstante(ofstream& arch) {
    arch << "Estante: " << id << endl;
    arch << "Capacidad: " << capacidad << setw(5) << " " << "Disponible: " << 
            disponible << endl;
    for(int i = 0; i < 100; i++)
        arch.put('=');
    arch << endl;
    for(int i = 0; i < vlibros.size(); i++){
        vlibros[i].imprimirLibro(arch);
        arch << endl;
    }
}
