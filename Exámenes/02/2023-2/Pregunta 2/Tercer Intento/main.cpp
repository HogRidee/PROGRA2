/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 7 de julio de 2024, 9:41
 */

#include "Flota.h"

int main(int argc, char** argv) {
    Flota flota;
    
    flota.cargar_vehiculos();
    flota.cargar_pedidos();
    flota.mostrar_vehiculos();
    
    return 0;
}

