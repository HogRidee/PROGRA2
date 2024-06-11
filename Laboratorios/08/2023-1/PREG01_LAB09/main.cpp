/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 3 de junio de 2024, 13:19
 */

#include "Tesoreria.h"

using namespace std;

int main(int argc, char** argv) {

    Tesoreria OTeso;
    
    OTeso.cargaescalas();
    OTeso.cargaalumnos();
    OTeso.cargaactualizaboleta();
    OTeso.imprimeboleta();
    
    return 0;
}

