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
        cout << cliente.dni << " " << cliente.nombre << " " << cliente.telefono
                << endl;
    }
    cout << "Se pudo leer todo el archivo clientes" << endl;
    
    archClientes.close();
    
    ifstream archProductos;
    Producto producto;
    
    AperturaDeUnArchivoDeTextosParaLeer(archProductos, "Productos.csv");
    
    while(true){ 
        archProductos >> producto;
        if (archProductos.eof()) break;
        cout << producto.codigo << " " << producto.descripcion << " " <<
                producto.precio << " " << producto.stock << endl;
    }
    
    cout << "Se pudo leer todo el archivo productos" << endl;
    
    archProductos.close();
    
    ifstream archPedidos;
    Pedido pedido;
    
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos, "Pedidos.csv");
    
    while(true){
        if(archPedidos.eof()) break;
        archPedidos >> pedido;
    }
    
    cout << "Se pudo leer todo el archivo pedidos" << endl;
    
    archPedidos.close();
    
    return 0;
}

