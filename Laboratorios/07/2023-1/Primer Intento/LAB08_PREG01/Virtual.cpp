/* 
 * File:   Virtual.cpp
 * Author: Ivan
 * 
 * Created on 26 de mayo de 2024, 17:25
 */

#include "Virtual.h"

Virtual::Virtual() {
    licencia = nullptr;
    total = 100.0;
}

Virtual::Virtual(const Virtual& orig) {
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

void Virtual::SetLicencia(const char* cad) {
    if(licencia) delete[] licencia;
    licencia = new char[strlen(cad)+1];
    strcpy(licencia, cad);
}

void Virtual::GetLicencia(char *cad) const {
    if(licencia == nullptr) cad[0] = 0;
    else strcpy(cad, licencia);
}

