/* 
 * File:   Flota.h
 * Author: Ivan
 *
 * Created on 7 de julio de 2024, 9:46
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

using namespace std;

class Flota {
private:
    map<string, class Vehiculo*>vehiculos;
public:
    Flota();
    virtual ~Flota();
    
    void cargar_vehiculos();
    void cargar_pedidos();
    void mostrar_vehiculos();
    const map<string, class Vehiculo*>& obtenerVehiculos() const;
};

#endif /* FLOTA_H */

