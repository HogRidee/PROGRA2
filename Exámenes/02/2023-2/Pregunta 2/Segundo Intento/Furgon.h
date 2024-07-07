/* 
 * File:   Furgon.h
 * Author: Ivan
 *
 * Created on 6 de julio de 2024, 13:45
 */

#ifndef FURGON_H
#define FURGON_H

#include <list>

#include "Pedido.h"
#include "Vehiculo.h"

class Furgon : public Vehiculo{
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

