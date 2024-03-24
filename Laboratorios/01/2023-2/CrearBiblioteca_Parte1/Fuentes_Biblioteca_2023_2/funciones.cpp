#include "funciones.h"

bool operator >> (istream &in, Cliente &cliente){   
    in >> cliente.dni;
    if(in.eof()) return false;
    in.get();
    
    in.getline(cliente.nombre, 60, ',');
    
    in >> cliente.telefono;

    return true;
}

bool operator >> (istream &in, Producto &producto){
    char c;
    int i = 0;
    while(true){
        in.get(c);
        if(c == ',' or in.eof()) break;
        if(i < 7) { // Asegúrate de que no desbordas el array
            producto.codigo[i] = c; 
        }
        i++;
    }
    producto.codigo[i] = '\0';
    if(in.eof()) return false;
    
    in.getline(producto.descripcion, 60, ',');
    
    in >> producto.precio;
    in.get();
    
    in >> producto.stock;
    
    return true;
}

bool operator >> (istream &in, Pedido &pedido){
    char buffer[60], c;
    int i = 0;
    while(in.get(c)){
        if(c == ',' or in.eof()) break;
        buffer[i] = c;
        i++;
    }
    buffer[i] = '\0';
    if(in.eof()) return false;
    strcpy(pedido.CodigoProducto, buffer);
    
    in >> pedido.dniCliente;
    
    pedido.precioProducto = 0.0;
    
    return true;
}