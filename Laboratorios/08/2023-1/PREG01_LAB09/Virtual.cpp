/* 
 * File:   Virtual.cpp
 * Author: Ivan
 * 
 * Created on 3 de junio de 2024, 13:38
 */

#include "Virtual.h"

Virtual::Virtual() {
    licencia = nullptr;
    total = 0.0;
}

Virtual::Virtual(const Virtual& orig) {
}

Virtual::~Virtual() {
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

