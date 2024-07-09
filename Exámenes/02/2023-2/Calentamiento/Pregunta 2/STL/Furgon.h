/* 
 * File:   Furgon.h
 * Author: Ivan
 *
 * Created on 9 de julio de 2024, 8:19
 */

#ifndef FURGON_H
#define FURGON_H

#include <list>

#include "Vehiculos.h"
#include "Pedido.h"

class Furgon: public Vehiculos {
private:
    int filas;
    int puertas;
    list<class Pedido>depositos;
public:
    Furgon();
    Furgon(const Furgon& orig);
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

