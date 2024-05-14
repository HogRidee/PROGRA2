/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 14 de mayo de 2024, 8:47
 */

#include "Pregunta01Examen01PunterosMultiples.h"

int main(int argc, char** argv) {

    char **codigoDelProducto;
    int **fechaClienteCantidad;
    
    cargarPedidos(fechaClienteCantidad, codigoDelProducto, "Pedidos.csv");
    pruebaDeCargaDePedidos(fechaClienteCantidad, codigoDelProducto, 
            "PruebaPedidos.txt");  
    
    return 0;
}

