/* 
 * File:   Boleta.cpp
 * Author: Ivan
 * 
 * Created on 11 de junio de 2024, 17:09
 */

#include <iomanip>

using namespace std;

#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"

#include "Boleta.h"


Boleta::Boleta() {
    pboleta = nullptr;
}

Boleta::Boleta(const Boleta& orig) {
}

Boleta::~Boleta() {
    if(pboleta) delete[] pboleta;
}

void Boleta::asignaMemoria(char tipo){
    switch(tipo){
        case 'P':
            pboleta = new class Presencial;
            break;
        case 'S':
            pboleta = new class Semipresencial;
            break;
        case 'V':
            pboleta = new class Virtual;
            break;
    }
}

void Boleta::leeDatos(ifstream &file){
    
}

