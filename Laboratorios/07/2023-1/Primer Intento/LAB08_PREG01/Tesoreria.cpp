/* 
 * File:   Tesoreria.cpp
 * Author: Ivan
 * 
 * Created on 26 de mayo de 2024, 18:07
 */

#include <iostream>
#include <fstream>

using namespace std;

#include "Tesoreria.h"
#include "FuncionesExtras.h"

Tesoreria::Tesoreria() {
}

Tesoreria::Tesoreria(const Tesoreria& orig) {
}

Tesoreria::~Tesoreria() {
}

void Tesoreria::cargaescalas(){
    ifstream file("escalas.csv");
    if(not file.is_open()){
        cout << "ERROR: No se pudo abrir el archivo escalas.csv" << endl;
        exit(1);
    }
    int codigo;
    double precio;
    char c;
    while(true){
        file >> codigo;
        if(file.eof()) break;
        file >> c >> precio;
        lescala[codigo-1].SetCodigo(codigo);
        lescala[codigo-1].SetPrecio(precio);
    }
    file.close();
}

void Tesoreria::cargaalumnos(){
    ifstream file("Alumnos.csv");
    if(not file.is_open()){
        cout << "ERROR: No se pudo abrir el archivo Alumnos.csv" << endl;
        exit(1);
    }
    int codigo;
    char modalidad, c, *nombre;
    while(true){
        file >> modalidad;
        if(file.eof()) break;
        file >> c >> codigo >> c;
        nombre = leerCadena(file, 100, ',');
        
    }
    file.close();
}

