/* 
 * File:   Semipresencial.h
 * Author: Ivan
 *
 * Created on 17 de junio de 2024, 13:00
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
    virtual ~Semipresencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &file);
    void imprime(ofstream &file);
    void actualizaTotal(double precioEscala);
};

#endif /* SEMIPRESENCIAL_H */

