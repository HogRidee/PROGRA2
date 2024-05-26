/* 
 * File:   Alumno.cpp
 * Author: Ivan
 * 
 * Created on 26 de mayo de 2024, 9:48
 */

#include "Alumno.h"

Alumno::Alumno() {
    codigo = 0;
    nombre = nullptr;
    escala = 0;
    total = 0.0;
}

Alumno::Alumno(const Alumno& orig) {
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

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(char* nombre) {
    this->nombre = nombre;
}

char* Alumno::GetNombre() const {
    return nombre;
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

