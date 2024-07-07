/* 
 * File:   Furgon.h
 * Author: Ivan
 *
 * Created on 7 de julio de 2024, 9:45
 */

#ifndef FURGON_H
#define FURGON_H

#include <list>

#include "Pedido.h"
#include "Vehiculo.h"

using namespace std;

class Furgon: public Vehiculo {
private:
    int filas;
    int puertas;
    list<class Pedido>depositos;
public:
    Furgon();
    virtual ~Furgon();
    void SetPuertas(int puertas);
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;
    
    void leer(ifstream &arch);
    void mostrar(ofstream &arch);
    bool insertar(class Pedido pedido);
};

#endif /* FURGON_H */

