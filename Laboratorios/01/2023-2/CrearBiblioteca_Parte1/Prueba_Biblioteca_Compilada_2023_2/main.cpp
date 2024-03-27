/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 27 de marzo de 2024, 15:16
 */

#include "funcionesLib.h"

int main(int argc, char** argv) {

    ifstream archClientes;
    Cliente *arrClientes = nullptr;
    arrClientes = new Cliente[NCLIENTES];
    int nClientes = 0;
    
    AperturaDeUnArchivoDeTextosParaLeer(archClientes, "Clientes.csv");

    while(true){
        if(!(archClientes >> arrClientes[nClientes])){
            arrClientes[nClientes].dni = 0;
            break;
        }
        nClientes++;
    }
    
    for (int i = 0; i <= nClientes; i++){
        cout << arrClientes[i].dni << " " << arrClientes[i].nombre << " " << 
                arrClientes[i].telefono << endl;
    }
    
    cout << "Se leyo correctamente el archivo clientes" << endl;
    
    ifstream archProductos;
    Producto *arrProductos = nullptr;
    arrProductos = new Producto[NPRODUCTOS];
    int nProductos = 0;
    
    AperturaDeUnArchivoDeTextosParaLeer(archProductos, "Productos.csv");
    
    while(true){ 
        if (!(archProductos >> arrProductos[nProductos])){
            strcpy(arrProductos[nProductos].codigo, "XXXXXXX");
            break;
        }
        nProductos++;
    }
    
    for (int i = 0; i <= nProductos; i++){
        cout << arrProductos[i].codigo << " " << arrProductos[i].descripcion << " " << 
                arrProductos[i].precio << " " << arrProductos[i].stock << endl;
    }
    
    cout << "Se leyo el archivo productos correctamente" << endl;

    ifstream archPedidos;
    Pedido pedido;
    
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos, "Pedidos.csv");
    
    while(archPedidos >> pedido){
        arrProductos += pedido;
        arrClientes += pedido;
    }
    
    for (int i = 0; i < nClientes; i++){
        cout << fixed << setprecision(2);
        cout << right << setw(10) << arrClientes[i].montoTotal << " " << 
               arrClientes[i].cantidadProductosEntrgados << " " <<
                arrClientes[i].productosEntregados[0].codigo << " " <<
                arrClientes[i].productosEntregados[0].precio << endl;
    }
    
    cout << "Se leyo y asigno el archivo pedidos correctamente" << endl;
    
    archPedidos.close();
    archProductos.close();
    archClientes.close();
    
    ofstream archReporteClientes;
    
    AperturaDeUnArchivoDeTextosParaEscribir(archReporteClientes, 
            "reporteClientes.txt");
    
    for (int i = 0; i < nClientes; i++){
        archReporteClientes << arrClientes[i];
    }
    
    cout << "Se imprimio correctamente la informacion en el archivo reporteClientes.txt" 
            << endl;
    
    archReporteClientes.close();
    
    ofstream archReporteProductos;
    
    AperturaDeUnArchivoDeTextosParaEscribir(archReporteProductos, 
            "reporteProductos.txt");
    
    for (int i = 0; i < nProductos; i++){
        archReporteProductos << arrProductos[i];
    }
    
    cout << "Se imprimio correctamente la informacion en el archivo reporteProductos.txt"
            << endl;
    
    archReporteProductos.close();
    
    return 0;
}

