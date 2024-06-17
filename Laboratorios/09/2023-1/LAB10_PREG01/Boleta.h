/* 
 * File:   Boleta.h
 * Author: Ivan
 *
 * Created on 17 de junio de 2024, 13:06
 */

#ifndef BOLETA_H
#define BOLETA_H

#include <fstream>

using namespace std;

#include "Alumno.h"

class Boleta {
private:
    Alumno *pboleta;
public:
    Boleta();
    virtual ~Boleta();
    void asignaMemoria(char tipo);
    void leeDatos(ifstream &file);
    bool operator >(const class Boleta &dato) const;
    int GetCodigo() const;
    void SetNull();
    void imprimeBoleta(ofstream &file) const;
};

void operator << (ofstream &file, const class Boleta &boleta);

#endif /* BOLETA_H */

