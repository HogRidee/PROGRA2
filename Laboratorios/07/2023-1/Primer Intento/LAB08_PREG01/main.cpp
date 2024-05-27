/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 26 de mayo de 2024, 9:48
 */

#include "Tesoreria.h"

using namespace std;

int main(int argc, char** argv) {

    Tesoreria caja;
    
    caja.cargaescalas();
    caja.cargaalumnos();
//    caja.actualiza();
//    caja.imprime();
    
    return 0;
}

