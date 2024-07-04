/* 
 * File:   Pedido.h
 * Author: Ivan
 *
 * Created on 4 de julio de 2024, 10:30
 */

#ifndef PEDIDO_H
#define PEDIDO_H

#include <string>

using namespace std;

class Pedido {
private:
    string codigo;
    int cantidad;
    double peso;
public:
    Pedido();
    virtual ~Pedido();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(string codigo);
    string GetCodigo() const;
};

#endif /* PEDIDO_H */

