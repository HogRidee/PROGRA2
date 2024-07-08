/* 
 * File:   NLibro.cpp
 * Author: Ivan
 * 
 * Created on 7 de julio de 2024, 13:19
 */

#include "NLibro.h"

NLibro::NLibro() {
    plibro = nullptr;
}

NLibro::~NLibro() {
    //delete plibro;
}

void NLibro::asignarMemoria(char tipo){
    delete plibro;
    if(tipo == 'N') plibro = new class Novela;
    if(tipo == 'E') plibro = new class Enciclopedia;
    if(tipo == 'R') plibro = new class Revista;
}

double NLibro::leerLibro(ifstream& arch){
    plibro->leer(arch);
    return plibro->GetPeso();
}

void NLibro::imprimirLibro(ofstream& arch) {
    plibro->imprimir(arch);
}


