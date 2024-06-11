/* 
 * File:   Tesoreria.cpp
 * Author: Ivan
 * 
 * Created on 11 de junio de 2024, 17:15
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "Tesoreria.h"

Tesoreria::Tesoreria() {
}

Tesoreria::Tesoreria(const Tesoreria& orig) {
}

Tesoreria::~Tesoreria() {
}

void Tesoreria::cargaescalas(){
    ifstream file("escalas.csv");
    if(not file.is_open()){
        cout << "NO SE PUDO ABRIR EL ARCHIVO ESCALAS.CSV" << endl;
        exit(1);
    }
    int escala;
    double precio;
    char c;
    while(true){
        file >> escala;
        if(file.eof()) break;
        file >> c >> precio;
        lescala[escala-1].SetCodigo(escala);
        lescala[escala-1].SetPrecio(precio);
    }
    file.close();
}
void Tesoreria::cargaalumnos(){
    ifstream file("Alumnos.csv");
    if(not file.is_open()){
        cout << "ERROR: NO SE PUDO ABRIR EL ARCHIVO ALUMNOS.CSV" << endl;
        exit(1);
    }
    int nDatos = 0;
    char tipo, c;
    while(true){
        file >> tipo;
        if(file.eof()) break;
        file >> c;
        lboleta[nDatos].asignaMemoria(tipo);
        lboleta[nDatos].leeDatos(file);
        nDatos++;
    }
    file.close();
}
void Tesoreria::cargaactualizaboleta(){
    
}
void Tesoreria::imprimeboleta(){
    
}

