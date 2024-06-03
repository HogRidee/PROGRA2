/* 
 * File:   Presencial.h
 * Author: Ivan
 *
 * Created on 3 de junio de 2024, 13:31
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H

#include "Alumno.h"

class Presencial : public Alumno{
private:
    double recargo;
    double total;
public:
    Presencial();
    Presencial(const Presencial& orig);
    virtual ~Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
};

#endif /* PRESENCIAL_H */

