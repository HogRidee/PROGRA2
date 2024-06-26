/* 
 * File:   Alumno.cpp
 * Author: Ivan
 * 
 * Created on 17 de junio de 2024, 12:52
 */

#include "Alumno.h"

Alumno::Alumno() {
    codigo = 0;
    creditos = 0.0;
    escala = 0;
    nombre = nullptr;
    total = 0.0;
}

Alumno::~Alumno() {
    if(nombre) delete[] nombre;
}

void Alumno::SetTotal(double total) {
    this->total = total;
}

double Alumno::GetTotal() const {
    return total;
}

void Alumno::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Alumno::GetCreditos() const {
    return creditos;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(char* cad) {
    if(nombre) delete[] nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre, cad);
}

void Alumno::GetNombre(char *cad) const {
    if(nombre == nullptr) cad[0] = 0;
    else strcpy(cad, nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::lee(ifstream &file){
    char nomb[60], c;
    file >> codigo;
    file.get();
    file.getline(nomb, 60, ',');
    SetNombre(nomb);
    file >> escala >> c >> creditos;
    file.get();
}

void Alumno::imprime(ofstream &file){
    file.precision(2);
    file << fixed;
    file<<left<<setw(10)<<codigo<<setw(40)<<nombre<<right<<setw(3)<<escala 
            <<setw(12)<<creditos;
}

void Alumno::actualizaTotal(double pago){
    total = pago;
}


