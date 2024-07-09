/* 
 * File:   Flota.cpp
 * Author: Ivan
 * 
 * Created on 9 de julio de 2024, 8:20
 */

#include "Flota.h"

Flota::Flota() {
}

Flota::Flota(const Flota& orig) {
}

Flota::~Flota() {
}

void Flota::cargar_vehiculos() {
    ifstream arch("Vehiculos.csv", ios::in);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo Vehiculos.csv" << endl;
        exit(1);
    }
    char tipo;
    class Vehiculos *vehiculo = nullptr;
    while(true){
        arch >> tipo;
        if(arch.eof()) break;
        arch.get();
        if(tipo == 'F') vehiculo = new class Furgon;
        if(tipo == 'C') vehiculo = new class Camion;
        vehiculo->leer(arch);
        vehiculos[vehiculo->GetPlaca()] = vehiculo;
    }
}

void Flota::cargar_pedidos() {
    ifstream arch("Pedidos4.csv", ios::in);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo Pedidos4.csv" << endl;
        exit(1);
    }
    string placa;
    class Pedido pedido;
    while(true){
        getline(arch, placa, ',');
        if(arch.eof()) break;
        pedido.leerPedido(arch);
        auto it = vehiculos.find(placa);
        if(it != vehiculos.end()){
            class Vehiculos *veh = it->second;
            bool insertado = veh->insertar(pedido);
        }
    }
}

void Flota::mostrar_vehiculos() {
    ofstream arch("ReporteDeFlota.txt", ios::out);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo ReporteDeFlota.txt" << endl;
        exit(1);
    }
    arch << right << setw(50) << "REPORTE DE FLOTA" << endl;
    imprimirLinea(arch, 100, '=');
    for(auto x: vehiculos){
        class Vehiculos *veh = x.second;
        veh->mostrar(arch);
        imprimirLinea(arch, 100, '=');
    }
}
