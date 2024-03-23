/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 23 de marzo de 2024, 11:43
 */

#include <cstdlib>
#include <iostream>
#include "pruebas.h"

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

