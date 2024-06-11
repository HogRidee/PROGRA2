/* 
 * File:   Boleta.h
 * Author: Ivan
 *
 * Created on 11 de junio de 2024, 17:09
 */

#ifndef BOLETA_H
#define BOLETA_H

#include <fstream>

using namespace std;

#include "Alumno.h"

class Boleta {
private:
    class Alumno* pboleta;
public:
    Boleta();
    Boleta(const Boleta& orig);
    virtual ~Boleta();
    void asignaMemoria(char tipo);
    void leeDatos(ifstream &file);
};

#endif /* BOLETA_H */

