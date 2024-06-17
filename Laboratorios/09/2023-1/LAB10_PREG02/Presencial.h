/* 
 * File:   Presencial.h
 * Author: Ivan
 *
 * Created on 17 de junio de 2024, 12:59
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H

#include "Alumno.h"

class Presencial: public Alumno {
private:
    double recargo;
    double total;
public:
    Presencial();
    virtual ~Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    void lee(ifstream &file);
    void imprime(ofstream &file);
    void actualizaTotal(double precioEscala);
};

#endif /* PRESENCIAL_H */

