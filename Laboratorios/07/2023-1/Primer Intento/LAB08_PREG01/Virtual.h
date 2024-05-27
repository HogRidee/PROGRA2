/* 
 * File:   Virtual.h
 * Author: Ivan
 *
 * Created on 26 de mayo de 2024, 17:25
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H

#include "Alumno.h"

class Virtual : public Alumno{
private:
    char *licencia;
    double total;
public:
    Virtual();
    Virtual(const Virtual& orig);
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(const char* cad);
    void GetLicencia(char* cad) const;
};

#endif /* VIRTUAL_H */

