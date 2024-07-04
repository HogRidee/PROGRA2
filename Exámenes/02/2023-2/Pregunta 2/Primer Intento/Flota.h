/* 
 * File:   Flota.h
 * Author: Ivan
 *
 * Created on 4 de julio de 2024, 11:01
 */

#ifndef FLOTA_H
#define FLOTA_H

#include <map>
#include <string>
#include <fstream>
#include <iostream>

#include "Vehiculo.h"
#include "Furgon.h"
#include "Camion.h"

using namespace std;

class Flota {
private:
    map<string, class Vehiculo>vehiculos;
public:
    Flota();
    virtual ~Flota();
    void cargar_vehiculos();
    void cargar_pedidos();
    void mostrar_vehiculos();
};

#endif /* FLOTA_H */

