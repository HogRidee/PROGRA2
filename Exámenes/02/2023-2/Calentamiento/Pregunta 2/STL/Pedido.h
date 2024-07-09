/* 
 * File:   Pedido.h
 * Author: Ivan
 *
 * Created on 9 de julio de 2024, 8:15
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
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(string codigo);
    string GetCodigo() const;
    
    void leerPedido(ifstream &arch);
    void mostrarPedido(ofstream &arch);
    
    void operator =(const Pedido &ped);
};

#endif /* PEDIDO_H */

