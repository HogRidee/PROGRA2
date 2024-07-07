/* 
 * File:   Enciclopedia.h
 * Author: Ivan
 *
 * Created on 7 de julio de 2024, 13:01
 */

#ifndef ENCICLOPEDIA_H
#define ENCICLOPEDIA_H

#include "Libro.h"

class Enciclopedia: public Libro {
private:
    int sku;
    int anho;
public:
    Enciclopedia();
    virtual ~Enciclopedia();
    void SetAnho(int anho);
    int GetAnho() const;
    void SetSku(int sku);
    int GetSku() const;
};

#endif /* ENCICLOPEDIA_H */

