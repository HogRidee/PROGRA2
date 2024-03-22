/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 22 de marzo de 2024, 04:31 PM
 */

#include <iostream>
#include "punto2D.hpp"

using namespace std;

int main(int argc, char** argv) {

    Punto2D p1{10, 5};
    
    cout << "Ingrese datos para p1:";
    cin >> p1;
    ++p1;
    cout << "P1 incrementado: ";
    cout << p1 << endl;
    
    return 0;
}

