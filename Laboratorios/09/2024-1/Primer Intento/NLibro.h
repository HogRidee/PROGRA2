/* 
 * File:   NLibro.h
 * Author: Ivan
 *
 * Created on 7 de julio de 2024, 13:19
 */

#ifndef NLIBRO_H
#define NLIBRO_H

#include "Libro.h"

class NLibro {
private:
    class Libro *plibro;
public:
    NLibro();
    virtual ~NLibro();
};

#endif /* NLIBRO_H */

