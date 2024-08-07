/* 
 * File:   Flota.cpp
 * Author: Ivan
 * 
 * Created on 4 de julio de 2024, 11:01
 */

#include "Flota.h"
#include "Utils.h"

Flota::Flota() {
}

Flota::~Flota() {
}

void Flota::cargar_vehiculos(){
    class Vehiculo *vehiculoPrototipo = nullptr;
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
        if(tipo == 'C') vehiculoPrototipo = new class Camion;
        else vehiculoPrototipo = new class Furgon;
        vehiculoPrototipo->leer(arch);
        class Vehiculo* vehiculoClonado = vehiculoPrototipo->clonar();
        vehiculos[vehiculoClonado->GetPlaca()] = vehiculoClonado;
        delete vehiculoPrototipo;
    }
}

void Flota::cargar_pedidos(){
    ifstream arch("Pedidos4.csv", ios::in);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo Pedidos4.csv" << endl;
        exit(1);
    }
    string placa, codigo;
    int cantidad;
    double peso;
    class Pedido pedido;
    while(true){
        getline(arch, placa, ',');
        if(arch.eof()) break;
        pedido.leerPedido(arch);
        auto it = vehiculos.find(placa);
        if(it != vehiculos.end()){
            Vehiculo *vehiculo = it->second;
            bool insertado = vehiculo->insertar(pedido);
        }
    }
}

void Flota::mostrar_vehiculos(){
    ofstream arch("ReporteDeFlota.txt", ios::out);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo ReporteDeFlota.txt" << endl;
        exit(1);
    }
    arch << right << setw(50) << "REPORTE DE FLOTA" << endl;
    imprimirLinea(arch, 100, '=');
    for(auto x: vehiculos){
        Vehiculo* veh = x.second;
        veh->mostrar(arch);
        imprimirLinea(arch, 100, '-');
    }
}