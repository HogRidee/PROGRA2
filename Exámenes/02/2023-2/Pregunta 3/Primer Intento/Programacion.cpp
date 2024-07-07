/* 
 * File:   Programacion.cpp
 * Author: Ivan
 * 
 * Created on 7 de julio de 2024, 10:49
 */

#include "Programacion.h"

Programacion::Programacion() {
}

Programacion::~Programacion() {
}

void Programacion::cargavehiculos(){
    fVehiculos.cargar_vehiculos();
    fVehiculos.cargar_pedidos();
}
    
void Programacion::cargaprogramacion(){
    auto vehiculos = fVehiculos.obtenerVehiculos();
    for(auto x: vehiculos){
        ADespachos.insertar(x.second);
    }
}
    
void Programacion::reducevehiculos(int n){
    ADespachos.eliminarNodosHoja(n);
}
    
void Programacion::muestraprogramacion(){
    ofstream arch("ReporteArbol.txt", ios::out);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo ReporteArbol.txt" << endl;
        exit(1);
    }
    ADespachos.imprimirArbol(arch);
}
