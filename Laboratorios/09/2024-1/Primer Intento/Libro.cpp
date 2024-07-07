/* 
 * File:   Libro.cpp
 * Author: Ivan
 * 
 * Created on 7 de julio de 2024, 12:56
 */

#include "Libro.h"

Libro::Libro() {
    nombre = nullptr;
    paginas = 0;
    peso = 0.0;
}

Libro::~Libro() {
    delete[] nombre;
}

void Libro::SetPeso(double peso) {
    this->peso = peso;
}

double Libro::GetPeso() const {
    return peso;
}

void Libro::SetPaginas(int paginas) {
    this->paginas = paginas;
}

int Libro::GetPaginas() const {
    return paginas;
}

void Libro::SetNombre(char* cad) {
    if(nombre) delete[] nombre;
    nombre = new char [strlen(cad)+1];
    strcpy(nombre, cad);
}

void Libro::GetNombre(char *cad) const {
    if(nombre == nullptr) cad[0] = 0;
    else strcpy(cad, nombre);
}

void Libro::leer(ifstream& arch){
    char buffer[100];
    arch.getline(buffer, 100, ',');
}
