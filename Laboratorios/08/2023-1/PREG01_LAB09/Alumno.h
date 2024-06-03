/* 
 * File:   Alumno.h
 * Author: Ivan
 *
 * Created on 3 de junio de 2024, 13:20
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include <cstring>

class Alumno {
private:
    int codigo;
    char *nombre;
    int escala;
    double creditos;
    double total;
public:
    Alumno();
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(const char* nombre);
    void GetNombre(char* cad) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
};

#endif /* ALUMNO_H */

