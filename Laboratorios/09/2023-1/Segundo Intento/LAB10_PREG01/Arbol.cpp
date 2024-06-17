/* 
 * File:   Arbol.cpp
 * Author: Ivan
 * 
 * Created on 17 de junio de 2024, 17:17
 */

#include "Arbol.h"

Arbol::Arbol() {
}

Arbol::~Arbol() {
}

void Arbol::crear(){
    ifstream file("Alumnos.csv");
    if(not file.is_open()){
        cout << "ERROR: No se pudo abrir el archivo alumnos.csv";
        exit(1);
    }
    char tipo;
    class Boleta boleta;
    while(true){
        file >> tipo;
        if(file.eof()) break;
        file.get();
        boleta.asignarMemoria(tipo);
        boleta.leerDatos(file);
        insertarR(raiz, boleta);
    }
    boleta.SetNull();
    file.close();
}

void Arbol::insertarR(class Nodo *&arbol, const class Boleta &dato){
    if(arbol == nullptr){
        arbol = new class Nodo;
        arbol->dboleta = dato;
        return;
    }
    if(arbol->dboleta > dato)
        insertarR(arbol->izq, dato);
    else
        insertarR(arbol->der, dato);
}