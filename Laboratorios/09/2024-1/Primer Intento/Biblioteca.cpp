/* 
 * File:   Biblioteca.cpp
 * Author: Ivan
 * 
 * Created on 7 de julio de 2024, 13:25
 */

#include "Biblioteca.h"

Biblioteca::Biblioteca() {
}

Biblioteca::~Biblioteca() {
}

void Biblioteca::carga(){
    ifstream arch("Estantes3.csv", ios::in);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo Estantes3.csv" << endl;
        exit(1);
    }
    ifstream arch2("Libros31.csv", ios::in);
    if(not arch2.is_open()){
        cout << "ERROR: No se pudo abrir el archivo Libros31.csv" << endl;
        exit(1);
    }
    int id;
    double capacidad;
    while(true){
        class NEstante *estante = new class NEstante;
        arch >> id;
        if(arch.eof()) break;
        arch.get();
        arch >> capacidad;
        estante->SetCapacidad(capacidad);
        estante->SetId(id);
        estante->cargarLibros(arch2);
        AEstante.insertar(estante);
    }
}
    
void Biblioteca::muestra(){
    ofstream arch("ReporteEstantes.txt", ios::out);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo ReporteEstantes.txt" << endl;
        exit(1);
    }
    AEstante.imprimir(arch);
}
    
void Biblioteca::prueba(int n){
    
}
