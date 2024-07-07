/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 7 de julio de 2024, 10:41
 */

#include "Programacion.h"

using namespace std;

int main(int argc, char** argv) {
    Programacion pro;
    
    pro.cargavehiculos();
    pro.cargaprogramacion();
    pro.reducevehiculos(10);
    pro.muestraprogramacion();
    
    return 0;
}

