/* 
 * File:   Programacion.h
 * Author: Ivan
 *
 * Created on 7 de julio de 2024, 10:49
 */

#ifndef PROGRAMACION_H
#define PROGRAMACION_H

#include "Flota.h"
#include "Arbol.h"

class Programacion {
private:
    class Arbol ADespachos;
    class Flota fVehiculos;
public:
    Programacion();
    virtual ~Programacion();
    
    friend class Flota;
    void cargavehiculos();
    void cargaprogramacion();
    void reducevehiculos(int n);
    void muestraprogramacion();
};

#endif /* PROGRAMACION_H */

