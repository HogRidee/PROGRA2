/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 20 de abril de 2024, 18:21
 */

#include "PunterosGenericos.h"
#include "MuestraPunteros.h"

using namespace std;

int main(int argc, char** argv) {
    void *productos,*clientes;
    
    cargaproductos(productos);
    cargaclientes(clientes);
    
//    cargapedidos(productos,clientes);
//    imprimereporte(clientes);
    
    return 0;
}

