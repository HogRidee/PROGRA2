/* 
 * File:   Furgon.h
 * Author: Ivan
 *
 * Created on 4 de julio de 2024, 10:55
 */

#ifndef FURGON_H
#define FURGON_H

#include <list>
#include <fstream>

#include "Vehiculo.h"
#include "Pedido.h"

using namespace std;

class Furgon : public Vehiculo{
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
};

#endif /* FURGON_H */

