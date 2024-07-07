/* 
 * File:   Revista.h
 * Author: Ivan
 *
 * Created on 7 de julio de 2024, 13:18
 */

#ifndef REVISTA_H
#define REVISTA_H

#include "Libro.h"

class Revista: public Libro {
private:
    int ISSN;
    int anho;
    int numero;
public:
    Revista();
    virtual ~Revista();
    void SetNumero(int numero);
    int GetNumero() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetISSN(int ISSN);
    int GetISSN() const;
};

#endif /* REVISTA_H */

