/* 
 * File:   Semipresencial.h
 * Author: Ivan
 *
 * Created on 3 de junio de 2024, 13:35
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H

#include "Alumno.h"

class Semipresencial: public Alumno {
private:
    double descuento;
    double total;
public:
    Semipresencial();
    Semipresencial(const Semipresencial& orig);
    virtual ~Semipresencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
};

#endif /* SEMIPRESENCIAL_H */

