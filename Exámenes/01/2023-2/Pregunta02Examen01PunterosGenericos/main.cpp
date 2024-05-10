/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 9 de mayo de 2024, 18:49
 */

#include "Pregunta02Examen01PunterosGenericos.h"

int main(int argc, char** argv) {

    void *productos;
    
    cargarProductos(productos, "Productos.csv");
    pruebaDeCargaDeProductos(productos);
    
    return 0;
}

