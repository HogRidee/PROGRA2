/* 
 * File:   Camion.h
 * Author: Ivan
 *
 * Created on 7 de julio de 2024, 9:43
 */

#ifndef CAMION_H
#define CAMION_H

#include <vector>

#include "Pedido.h"
#include "Vehiculo.h"

using namespace std;

class Camion: public Vehiculo{
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
    void mostrar(ofstream &arch);
    bool insertar(class Pedido pedido);
};

#endif /* CAMION_H */

