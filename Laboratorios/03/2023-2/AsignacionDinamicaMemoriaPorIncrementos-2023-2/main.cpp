/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 15 de abril de 2024, 16:56
 */

#include "AsignacionDinamicaMemoriaExacta.h"

int main(int argc, char** argv) {
    char ***productos,***codigoPedidos;
    int *stock, *fechaPedidos, ***dniCantPedidos;
    double *precios;
    lecturaDeProductos ("Productos.csv",productos, stock, precios);
    pruebaDeLecturaDeProductos ("ReporteDeProductos.txt" ,productos, stock, 
            precios);
    
//    lecturaDePedidos (“Pedidos.csv”, fechaPedidos, codigoPedidos, dniCantPedidos);
//    pruebaDeLecturaDePedidos (“ReporteDePedidos.txt”, fechaPedidos, codigoPedidos,
//            dniCantPedidos);
//    
//    reporteDeEnvioDePedidos (“ReporteDeEntregaDePedisos.txt”, productos, stock, 
//            precios, fechaPedidos, codigoPedidos, dniCantPedidos);
//    pruebaDeLecturaDeProductos (“ReporteDeProductosFinal.txt” ,productos, stock, 
//            precios);
    
    return 0;
}
