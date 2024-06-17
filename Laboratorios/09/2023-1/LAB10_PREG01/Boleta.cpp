/* 
 * File:   Boleta.cpp
 * Author: Ivan
 * 
 * Created on 17 de junio de 2024, 13:06
 */

#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"
#include "Boleta.h"

Boleta::Boleta() {
    pboleta = nullptr;
}

Boleta::~Boleta() {
    if(pboleta) delete pboleta;
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
    pboleta->lee(file);//polimorfismo
}

bool Boleta::operator >(const class Boleta &dato) const{
    return pboleta->GetCodigo() > dato.GetCodigo();
}

int Boleta::GetCodigo() const{
    return pboleta->GetCodigo();
}

void Boleta::SetNull(){
    pboleta = nullptr;
}

void operator << (ofstream &file, const class Boleta &boleta){
    boleta.imprimeBoleta(file);
}

void Boleta::imprimeBoleta(ofstream &file) const{
    pboleta->imprime(file);
} 


