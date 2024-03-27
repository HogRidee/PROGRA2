/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 27 de marzo de 2024, 15:25
 */

#include "funcionesLib.h"
#include "funciones.h"

int main(int argc, char** argv) {
    Cliente *arrClientes = nullptr;
    inicializarClientes(arrClientes);
    
    Producto *arrProductos = nullptr;
    inicializarProductos(arrProductos);
    
    procesarPedidos(arrClientes, arrProductos);
    
    imprimirReporte(arrClientes, arrProductos);
            
    return 0;
}

