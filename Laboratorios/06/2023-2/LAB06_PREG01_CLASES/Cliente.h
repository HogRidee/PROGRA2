/* 
 * File:   Cliente.h
 * Author: Ivan
 *
 * Created on 22 de mayo de 2024, 16:25
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include "ProductoEntregado.h"

class Cliente {
private:
    int dni;
    char *nombre;
    int telefono;
    ProductoEntregado productosEntregados[100];
    int cantidadProductosEntregados;
    double montoTotal;
public:
    Cliente();
    ~Cliente();
};

#endif /* CLIENTE_H */

