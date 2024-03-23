/* 
 * File:   main.cpp
 * Author: Ivan Araoz 20201216
 *
 * Created on 20 de marzo de 2024, 13:41
 */

#include "funciones.h"

int main(int argc, char** argv) {
    
    ifstream archClientes;
    Cliente cliente;
    
    AperturaDeUnArchivoDeTextosParaLeer(archClientes, "Clientes.csv");

    while(true){
        archClientes >> cliente;
        if(archClientes.eof()) break;
    }
    cout << "Se pudo leer todo el archivo clientes" << endl;
    
    archClientes.close();
    
    ifstream archProductos;
    Producto producto;
    
    AperturaDeUnArchivoDeTextosParaLeer(archProductos, "Productos.csv");
    
    while(true){
        if (archProductos.eof()) break; 
        archProductos >> producto;
    }
    
    archProductos.close();
    
    return 0;
}

