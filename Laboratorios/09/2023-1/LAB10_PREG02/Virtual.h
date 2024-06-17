/* 
 * File:   Virtual.h
 * Author: Ivan
 *
 * Created on 17 de junio de 2024, 13:02
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H

#include "Alumno.h"

class Virtual: public Alumno {
private:
    char *licencia;
    double total;
public:
    Virtual();
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(char* cad);
    void GetLicencia(char *cad) const;
    void lee(ifstream &file);
    void imprime(ofstream &file);
    void actualizaTotal(double precioEscala);
};

#endif /* VIRTUAL_H */

