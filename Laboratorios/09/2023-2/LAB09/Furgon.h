/* 
 * File:   Furgon.h
 * Author: Ivan
 *
 * Created on 20 de junio de 2024, 18:37
 */

#ifndef FURGON_H
#define FURGON_H

#include "Vehiculo.h"
#include "NPedido.h"
#include <list>

using namespace std;

class Furgon : public Vehiculo{
private:
    int filas;
    int puertas;
public:
    Furgon();
    virtual ~Furgon();
    void agregarPedido(NPedido pedido);
    void eliminarPedido();
};

#endif /* FURGON_H */

