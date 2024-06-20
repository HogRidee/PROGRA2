/* 
 * File:   Camion.h
 * Author: Ivan
 *
 * Created on 20 de junio de 2024, 17:59
 */

#ifndef CAMION_H
#define CAMION_H

#include "Vehiculo.h"
#include "NPedido.h"
#include <map>

using namespace std;

class Camion : public Vehiculo{
private:
    int ejes;
    int llantas;
    map<int, NPedido> mdeposito;
public:
    Camion();
    virtual ~Camion();
    bool agregarPedido(int id, NPedido pedido);
    void eliminarPedido(int id);
    void setLlantas(int llantas);
    int getLlantas() const;
    void setEjes(int ejes);
    int getEjes() const;
};

#endif /* CAMION_H */

