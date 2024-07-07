/* 
 * File:   Novela.cpp
 * Author: Ivan
 * 
 * Created on 7 de julio de 2024, 13:01
 */

#include "Novela.h"

Novela::Novela() {
    autor = nullptr;
}

Novela::~Novela() {
    delete[] autor;
}

void Novela::SetAutor(char* cad) {
    if(autor) delete[] autor;
    autor = new char[strlen(cad)+1];
    strcpy(autor, cad);
}

void Novela::GetAutor(char *cad) const {
    if(autor == nullptr) cad[0] = 0;
    else strcpy(cad, autor);
}

