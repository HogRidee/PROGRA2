#include "funcionesLib.h"
#include "funciones.h"

void inicializarClientes(Cliente *&arrClientes){
    ifstream archClientes;
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
    archClientes.close();
}

void inicializarProductos(Producto *&arrProductos){
    ifstream archProductos;
    arrProductos = new Producto[NPRODUCTOS];
    int nProductos = 0;
    AperturaDeUnArchivoDeTextosParaLeer(archProductos, "Productos.csv");
    while(true){
        if(!(archProductos >> arrProductos[nProductos])){
            strcpy(arrProductos[nProductos].codigo, "XXXXXXX");
            break;
        }
        nProductos++;
    }
    archProductos.close();
}

void procesarPedidos(Cliente *&arrClientes, Producto *&arrProductos){
    ifstream archPedidos;
    Pedido pedido;
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos, "Pedidos.csv");
    while(archPedidos >> pedido){
        arrProductos += pedido;
        arrClientes += pedido;
    }
    archPedidos.close();
}

void imprimirReporte(const Cliente *arrClientes, const Producto *arrProductos){
    ofstream archReporte;
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte, "reporte.txt");
    archReporte << setw(70) << " " << "INFORMACION DE LOS PRODUCTOS" << endl;
    imprimirLinea('*', 170, archReporte);
    int i = 0;
    while(true){
        if((strcmp(arrProductos[i].codigo, "XXXXXXX") == 0)) break;
        archReporte << arrProductos[i];
        archReporte << endl;
        i++;
    }
    archReporte << setw(70) << " " << "INFORMACION DE LOS CLIENTES" << endl;
    imprimirLinea('*', 170, archReporte);
    i = 0;
    while(true){
        if(arrClientes[i].dni == 0) break;
        archReporte << arrClientes[i];
        archReporte << endl;
        i++;
    }
    archReporte.close();
}

void imprimirLinea(char c, int n, ofstream &archReporte){
    for(int i = 0; i <= n; i++)
        archReporte.put(c);
    archReporte.put('\n');
}