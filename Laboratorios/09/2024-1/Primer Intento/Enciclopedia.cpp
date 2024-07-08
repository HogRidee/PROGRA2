/* 
 * File:   Enciclopedia.cpp
 * Author: Ivan
 * 
 * Created on 7 de julio de 2024, 13:01
 */

#include "Enciclopedia.h"

Enciclopedia::Enciclopedia() {
    anho = 0;
    sku = 0;
}

Enciclopedia::~Enciclopedia() {
}

void Enciclopedia::SetAnho(int anho) {
    this->anho = anho;
}

int Enciclopedia::GetAnho() const {
    return anho;
}

void Enciclopedia::SetSku(int sku) {
    this->sku = sku;
}

int Enciclopedia::GetSku() const {
    return sku;
}

void Enciclopedia::leer(ifstream& arch){
    Libro::leer(arch);
    arch >> sku;
    arch.get();
    arch >> anho;
    arch.get();
}

void Enciclopedia::imprimir(ofstream& arch) {
    Libro::imprimir(arch);
    arch << "SKU: " << sku << setw(5) << " " << "Año: " << anho << endl;
}
