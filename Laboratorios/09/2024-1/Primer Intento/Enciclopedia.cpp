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

