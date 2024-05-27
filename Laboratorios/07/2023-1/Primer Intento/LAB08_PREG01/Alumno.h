/* 
 * File:   Alumno.h
 * Author: Ivan
 *
 * Created on 26 de mayo de 2024, 9:48
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include <cstring>

class Alumno {
private:
    int codigo;
    char* nombre;
    int escala;
    double total;
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(const char* cad);
    void GetNombre(char *cad) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
};

#endif /* ALUMNO_H */

