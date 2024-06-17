/* 
 * File:   Boleta.h
 * Author: Ivan
 *
 * Created on 17 de junio de 2024, 17:14
 */

#ifndef BOLETA_H
#define BOLETA_H

#include <fstream>

using namespace std;

#include "Alumno.h"

class Boleta {
private:
    class Alumno *pboleta;
public:
    Boleta();
    virtual ~Boleta();
    void asignarMemoria(char tipo);
    void leerDatos(ifstream &file);
    bool operator > (const class Boleta &dato) const;
    int GetCodigo() const;
    void SetNull();
};


#endif /* BOLETA_H */

