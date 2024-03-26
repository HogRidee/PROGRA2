#include "funciones.h"

bool operator >> (istream &in, Cliente &cliente){   
    in >> cliente.dni;
    if(in.eof()) return false;
    in.get();
    
    in.getline(cliente.nombre, 60, ',');
    
    in >> cliente.telefono;
    
    cliente.cantidadProductosEntrgados = 0;
    cliente.montoTotal = 0.0;
    for (int i = 0; i < 20; i++){
        cliente.productosEntregados[i].codigo[0] = '\0';
        cliente.productosEntregados[i].precio = 0.0;
    }

    return true;
}

bool operator >> (istream &in, Producto &producto){
    leerCodigoProducto(in, producto);
    if(in.eof()) return false;
    
    in.getline(producto.descripcion, 60, ',');
    
    in >> producto.precio;
    in.ignore();
    
    in >> producto.stock;
    in.ignore();
    
    producto.cantidadClientesServidos = 0;
    producto.cantidadClientesNoServidos = 0;
    for (int j = 0; j < 20; j++){
        producto.clientesNoServidos[j] = 0;
        producto.clientesServidos[j] = 0;
    }
    return true;
}

void leerCodigoProducto (istream &in, Producto &producto){
    char c;
    int i = 0;
    while(true){
        in.get(c);
        if(c == ',' or in.eof()) break;
        producto.codigo[i] = c; 
        i++;
    }
    producto.codigo[i] = '\0';
}

bool operator >> (istream &in, Pedido &pedido){
    char c;
    int i = 0;
    in.ignore();
    while(in.get(c)){
        if(c == ',' or in.eof()) break;
        pedido.CodigoProducto[i] = c;
        i++;
    }
    pedido.CodigoProducto[i] = '\0';
    if(in.eof()) return false;
    
    in >> pedido.dniCliente;
    
    pedido.precioProducto = 0.0;
    
    return true;
}

void operator += (Cliente *arrClientes, const Pedido &pedido){
    int posicion;
    posicion = buscarCliente(arrClientes, pedido.dniCliente);
    if(posicion == -1) return;
    strcpy(arrClientes[posicion].productosEntregados[arrClientes[posicion].
    cantidadProductosEntrgados].codigo, pedido.CodigoProducto);
    arrClientes[posicion].productosEntregados[arrClientes[posicion].
    cantidadProductosEntrgados].precio += pedido.precioProducto;
    arrClientes[posicion].montoTotal += pedido.precioProducto;
    arrClientes[posicion].cantidadProductosEntrgados++;
}

int buscarCliente(Cliente *arrClientes, int dniPedido){
    int i = 0;
    while(true){
        if (arrClientes[i].dni == dniPedido){
            return i;
        }
        if(arrClientes[i].dni == 0){
            return -1;
        }
        i++;
    }
}

bool operator += (Producto *arrProductos, Pedido &pedido){
    int posicion;
    posicion = buscarCodigo(arrProductos, pedido);
    if(posicion == -1) return false;
    pedido.precioProducto = arrProductos[posicion].precio;
    if(arrProductos[posicion].stock > 0){
        arrProductos[posicion].clientesServidos[arrProductos[posicion].
        cantidadClientesServidos] = pedido.dniCliente;
        arrProductos[posicion].cantidadClientesServidos++;
        arrProductos[posicion].stock--;
        return true;
    }
    else{
        arrProductos[posicion].clientesNoServidos[arrProductos[posicion].
        cantidadClientesNoServidos] = pedido.dniCliente;
        arrProductos[posicion].cantidadClientesNoServidos++;
        return false;
    }
}

int buscarCodigo(Producto *arrProductos, const Pedido &pedido){
    int i = 0;
    while(true){
        if(strcmp(arrProductos[i].codigo, pedido.CodigoProducto) == 0){
            return i;
        }
        if (strcmp(arrProductos[i].codigo, "XXXXXXX") == 0) return -1;
        i++;
    }
}