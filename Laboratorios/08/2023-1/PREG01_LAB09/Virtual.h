/* 
 * File:   Virtual.h
 * Author: Ivan
 *
 * Created on 3 de junio de 2024, 13:38
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
    void SetLicencia(char* cad);
    void GetLicencia(char *cad) const;
};

#endif /* VIRTUAL_H */

