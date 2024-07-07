/* 
 * File:   Novela.h
 * Author: Ivan
 *
 * Created on 7 de julio de 2024, 13:01
 */

#ifndef NOVELA_H
#define NOVELA_H

#include "Libro.h"

class Novela: public Libro {
private:
    char *autor;
public:
    Novela();
    virtual ~Novela();
    void SetAutor(char* cad);
    void GetAutor(char *cad) const;
};

#endif /* NOVELA_H */

