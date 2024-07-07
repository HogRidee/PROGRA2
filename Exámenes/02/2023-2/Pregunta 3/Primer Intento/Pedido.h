/* 
 * File:   Pedido.h
 * Author: Ivan
 *
 * Created on 7 de julio de 2024, 9:41
 */

#ifndef PEDIDO_H
#define PEDIDO_H

#include <string>
#include <fstream>
#include <iomanip>

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
    
    void mostrarPedido(ofstream &arch);
    void leerPedido(ifstream &arch);
};

#endif /* PEDIDO_H */

