/* 
 * File:   Flota.h
 * Author: Ivan
 *
 * Created on 6 de julio de 2024, 13:46
 */

#ifndef FLOTA_H
#define FLOTA_H

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

#include "Vehiculo.h"
#include "Camion.h"
#include "Furgon.h"
#include "Util.h"

class Flota {
private:
    map<string, class Vehiculo*>vehiculos;
public:
    Flota();
    Flota(const Flota& orig);
    virtual ~Flota();
    
    void cargar_vehiculos();
    void cargar_pedidos();
    void mostrar_vehiculos();
};

#endif /* FLOTA_H */

