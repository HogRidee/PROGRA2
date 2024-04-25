/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 25 de abril de 2024, 9:44
 */

#include "PunterosGenericos.h"
#include "MuestraPunteros.h"

using namespace std;

int main(int argc, char** argv) {
    void *productos,*clientes;
    
    cargaproductos(productos);
    imprimeproductos(productos);
    
    cargaclientes(clientes);
    imprimeclientes(clientes);
    
    cargapedidos(productos,clientes);
    imprimerepfinal(clientes);
    
    imprimereporte(clientes);
    
    return 0;
}

