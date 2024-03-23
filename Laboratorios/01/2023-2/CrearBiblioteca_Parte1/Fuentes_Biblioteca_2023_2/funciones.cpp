#include "funciones.h"

bool operator >> (istream &in, Cliente &cliente){   
    in >> cliente.dni;
    if(in.eof()) return false;
    cout << cliente.dni << " ";
    in.get();
    
    in.getline(cliente.nombre, 60, ',');
    //strcpy(cliente.nombre, buffer);
    cout << cliente.nombre << " ";
    
    in >> cliente.telefono;
    cout << cliente.telefono << endl;
    return true;
}

bool operator >> (istream &in, Producto &producto){
    char buffer[60], c;
    int i = 0;
    while(in.get(c)){
        if(c == ',' or in.eof()) break;
        buffer[i] = c;
        i++;
    }
    buffer[i] = '\0';
    if(in.eof()) return false;
    strcpy(producto.codigo, buffer);
    cout << producto.codigo << " ";
    
    in.getline(buffer, 60, ',');
    strcpy(producto.descripcion, buffer);
    cout << producto.descripcion << " ";
    
    in >> producto.precio;
    in.get();
    cout << producto.precio << " ";
    
    in >> producto.stock;
    cout << producto.stock << endl;
    
    return true;
}