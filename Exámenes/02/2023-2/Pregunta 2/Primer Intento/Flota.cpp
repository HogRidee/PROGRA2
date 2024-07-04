/* 
 * File:   Flota.cpp
 * Author: Ivan
 * 
 * Created on 4 de julio de 2024, 11:01
 */

#include "Flota.h"

Flota::Flota() {
}

Flota::~Flota() {
}

void Flota::cargar_vehiculos(){
    class Vehiculo *vehiculo = nullptr;
    char tipo;
    ifstream arch("Vehiculos.csv", ios::in);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo Vehiculos.csv" << endl;
        exit(1);
    }
    while(true){
        arch >> tipo;
        if(arch.eof()) break;
        arch.get();
        if(tipo == 'C') vehiculo = new class Camion;
        else vehiculo = new class Furgon;
        vehiculo->leer(arch);
        vehiculos[vehiculo->GetPlaca()] = vehiculo;
    }
    
    for(auto x: vehiculos){
        cout << x.second;
    }
}

void Flota::cargar_pedidos(){
    
}

void Flota::mostrar_vehiculos(){
    
}