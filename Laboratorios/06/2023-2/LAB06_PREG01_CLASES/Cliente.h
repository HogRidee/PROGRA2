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
    void SetMontoTotal(double );
    double GetMontoTotal() const;
    void SetCantidadProductosEntregados(int );
    int GetCantidadProductosEntregados() const;
    void SetProductosEntregados(ProductoEntregado);
    //ProductoEntregado* GetProductosEntregados() const;
    void SetTelefono(int );
    int GetTelefono() const;
    void SetNombre(char* );
    char* GetNombre() const;
    void SetDni(int );
    int GetDni() const;
};

#endif /* CLIENTE_H */

