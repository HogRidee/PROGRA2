/* 
 * File:   ProductoEntregado.h
 * Author: Ivan
 *
 * Created on 22 de mayo de 2024, 16:13
 */

#ifndef PRODUCTOENTREGADO_H
#define PRODUCTOENTREGADO_H

#include <cstring>

class ProductoEntregado {
private:
    char *codigo;
    double precio;
public:
    ProductoEntregado();
    ~ProductoEntregado();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(char* codigo);
    char* GetCodigo() const;
};

#endif /* PRODUCTOENTREGADO_H */

