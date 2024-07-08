/* 
 * File:   NEstante.h
 * Author: Ivan
 *
 * Created on 7 de julio de 2024, 13:20
 */

#ifndef NESTANTE_H
#define NESTANTE_H

#include <vector>
#include <fstream>
#include <iostream>

#include "NLibro.h"
#include "NEstante.h"
#include "Arbol.h"

using namespace std;

class NEstante {
private:
    int id;
    double capacidad;
    double disponible;
    vector<class NLibro>vlibros;
    class NEstante *izq;
    class NEstante *der;
public:
    NEstante();
    virtual ~NEstante();
    void SetDisponible(double disponible);
    double GetDisponible() const;
    void SetCapacidad(double capacidad);
    double GetCapacidad() const;
    void SetId(int id);
    int GetId() const;
    
    friend class Arbol;
    void cargarLibros(ifstream &arch);
    void imprimirEstante(ofstream &arch);
};

#endif /* NESTANTE_H */

