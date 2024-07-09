/* 
 * File:   Flota.h
 * Author: Ivan
 *
 * Created on 9 de julio de 2024, 8:20
 */

#ifndef FLOTA_H
#define FLOTA_H

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

#include "Vehiculos.h"
#include "Furgon.h"
#include "Camion.h"
#include "Util.h"

class Flota {
private:
    map<string, class Vehiculos*>vehiculos;    
public:
    Flota();
    Flota(const Flota& orig);
    virtual ~Flota();
    
    void cargar_vehiculos();
    void cargar_pedidos();
    void mostrar_vehiculos();
};

#endif /* FLOTA_H */

