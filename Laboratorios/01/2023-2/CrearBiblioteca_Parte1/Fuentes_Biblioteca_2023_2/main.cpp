/* 
 * File:   main.cpp
 * Author: Ivan Araoz 20201216
 *
 * Created on 20 de marzo de 2024, 13:41
 */

#include "funciones.h"

int main(int argc, char** argv) {
    
    ifstream archClientes;
    Cliente *arrClientes = nullptr;
    arrClientes = new Cliente[NCLIENTES];
    int nClientes = 0;
    
    AperturaDeUnArchivoDeTextosParaLeer(archClientes, "Clientes.csv");

    while(true){
        archClientes >> arrClientes[nClientes];
        if(archClientes.eof()){
            arrClientes[nClientes+1].dni = 0;
            break;
        }
        nClientes++;
    }
    
    archClientes.close();
    
    ifstream archProductos;
    Producto *arrProductos = nullptr;
    arrProductos = new Producto[NPRODUCTOS];
    int nProductos = 0;
    
    AperturaDeUnArchivoDeTextosParaLeer(archProductos, "Productos.csv");
    
    while(true){ 
        archProductos >> arrProductos[nProductos];
        if (archProductos.eof()){
            strcpy(arrProductos[nProductos+1].codigo, "XXXXXXX");
            break;
        }
        nProductos++;
    }

    for (int i = 0; i <= nProductos; i++){
        cout << arrProductos[i].codigo << endl;
    }
    
    archProductos.close();
    
    ifstream archPedidos;
    Pedido pedido;
    
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos, "Pedidos.csv");
    
    while(true){
        archPedidos >> pedido;
        if(archPedidos.eof()) break;
        // arrClientes += pedido;
        cout << pedido.CodigoProducto << " " << pedido.dniCliente << " " <<
                pedido.precioProducto << endl;
    }
    
    cout << "Se pudo leer todo el archivo pedidos" << endl;
    
    archPedidos.close();
    
    for (int i = 0; i < nClientes; i++){
        cout << arrClientes[i].dni << " " << arrClientes[i].nombre << " "
                << arrClientes[i].telefono << " " <<
                arrClientes[i].productosEntregados[2].codigo << " " << 
                arrClientes[i].montoTotal << " " << 
                arrClientes[i].cantidadProductosEntrgados << endl;
    }
    
    return 0;
}

