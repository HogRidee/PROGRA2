/* 
 * File:   Revista.cpp
 * Author: Ivan
 * 
 * Created on 7 de julio de 2024, 13:18
 */

#include "Revista.h"

Revista::Revista() {
    ISSN = 0;
    anho = 0;
    numero = 0;
}

Revista::~Revista() {
}

void Revista::SetNumero(int numero) {
    this->numero = numero;
}

int Revista::GetNumero() const {
    return numero;
}

void Revista::SetAnho(int anho) {
    this->anho = anho;
}

int Revista::GetAnho() const {
    return anho;
}

void Revista::SetISSN(int ISSN) {
    this->ISSN = ISSN;
}

int Revista::GetISSN() const {
    return ISSN;
}

