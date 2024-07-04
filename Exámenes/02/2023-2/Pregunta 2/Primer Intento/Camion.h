/* 
 * File:   Camion.h
 * Author: Ivan
 *
 * Created on 4 de julio de 2024, 10:42
 */

#ifndef CAMION_H
#define CAMION_H

#include <vector>
#include <fstream>

#include "Vehiculo.h"
#include "Pedido.h"

using namespace std;

class Camion : public Vehiculo{
private:
    int ejes;
    int llantas;
    vector<class Pedido>depositos;
public:
    Camion();
    virtual ~Camion();
    void SetLlantas(int llantas);
    int GetLlantas() const;
    void SetEjes(int ejes);
    int GetEjes() const;
    
    void leer(ifstream &arch);
};

#endif /* CAMION_H */

