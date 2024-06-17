/* 
 * File:   Arbol.cpp
 * Author: Ivan
 * 
 * Created on 17 de junio de 2024, 13:12
 */

#include "Arbol.h"

Arbol::Arbol() {
    raiz = nullptr;
}

Arbol::~Arbol() {
}

void Arbol::crear(){
    ifstream file("Alumnos.csv");
    if(not file.is_open()){
        cout << "ERROR: No se pudo abrir el archivo Alumnos.csv" << endl;
        exit(1);
    }
    char tipo, c;
    Boleta boleta;
    while(true){
        file >> tipo;
        if(file.eof()) break;
        file >> c;
        boleta.asignaMemoria(tipo);
        boleta.leeDatos(file);
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

void Arbol::mostrarEnOrden(){
    ofstream file("ReporteArbol.txt");
    if(not file.is_open()){
        cout << "ERROR: No se pudo abrir el archivo ReporteArbol.txt";
        exit(1);
    }
    file << left << setw(10) << "Codigo" << setw(40) << "Nombre" << setw(8) << 
            "Escala" << setw(10) << "Creditos" << setw(12) << "Licencia" << 
            setw(10)<<"Total"<<endl;
    for(int i = 0; i < 90; i++)
        file.put('=');
    file << endl;
    mostrarEnOrdenR(file, raiz);
    cout << endl;
}

void Arbol::mostrarEnOrdenR(ofstream &file, class Nodo *raiz){
    if(raiz){
        mostrarEnOrdenR(file, raiz->izq);
        file << raiz->dboleta;
        mostrarEnOrdenR(file, raiz->der);
    }
}
