#include <cstdlib>
#include "funciones.h"

using namespace std;

int main(int argc, char** argv) {
    char ***productos;
    int *stock;
    double *precios;
    lecturaDeProductos("Productos.csv", productos, stock, precios);
    pruebaDeLecturaDeproductos("ReporteDeprodutos.txt", productos, stock, precios);
    /**/
    int *fechaPedidos;
    char ***codigoPedidos;
    int ***dniCantPedidos;
    lecturaDePedidos("Pedidos.csv", fechaPedidos, codigoPedidos, dniCantPedidos);
    pruebaDelecturaDepedidos("ReporteDePedidos.txt", fechaPedidos, codigoPedidos, dniCantPedidos);
    return 0;
}

