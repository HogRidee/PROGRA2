/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 7 de julio de 2024, 12:55
 */

#include "Biblioteca.h"

using namespace std;

int main(int argc, char** argv) {
    
    Biblioteca bli;
    
    bli.carga();
    bli.muestra();
    bli.prueba(8);
    
    return 0;
}

