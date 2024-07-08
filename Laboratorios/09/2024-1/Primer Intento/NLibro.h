/* 
 * File:   NLibro.h
 * Author: Ivan
 *
 * Created on 7 de julio de 2024, 13:19
 */

#ifndef NLIBRO_H
#define NLIBRO_H

#include "Libro.h"
#include "Enciclopedia.h"
#include "Novela.h"
#include "Revista.h"

class NLibro {
private:
    class Libro *plibro;
public:
    NLibro();
    virtual ~NLibro();
    
    void asignarMemoria(char tipo);
    double leerLibro(ifstream &arch);
    void imprimirLibro(ofstream &arch);
};

#endif /* NLIBRO_H */

