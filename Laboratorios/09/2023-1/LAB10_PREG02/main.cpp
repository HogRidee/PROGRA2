/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 17 de junio de 2024, 15:43
 */

#include "Tesoreria.h"

using namespace std;

int main(int argc, char** argv) {

    Tesoreria ABoleta;
    
    ABoleta.cargaalumnos();
    ABoleta.actualizaboleta();
    ABoleta.imprimeboleta();
    
    return 0;
}

