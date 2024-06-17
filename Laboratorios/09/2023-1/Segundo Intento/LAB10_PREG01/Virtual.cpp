/* 
 * File:   Virtual.cpp
 * Author: Ivan
 * 
 * Created on 17 de junio de 2024, 17:10
 */

#include "Virtual.h"

Virtual::Virtual() {
    licencia = nullptr;
    total = 0.0;
}

Virtual::~Virtual() {
    if(licencia) delete[] licencia;
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(char* cad) {
    if(licencia) delete[] licencia;
    licencia = new char[strlen(cad)+1];
    strcpy(licencia, cad);
}

void Virtual::GetLicencia(char *cad) const {
    if(licencia == nullptr) cad[0] = 0;
    else strcpy(cad, licencia);
}
    
void Virtual::lee(ifstream &file){
    char lic[10];
    Alumno::lee(file);
    file >> lic;
    file.get();
    SetLicencia(lic);
}

