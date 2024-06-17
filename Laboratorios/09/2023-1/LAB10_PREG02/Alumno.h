/* 
 * File:   Alumno.h
 * Author: Ivan
 *
 * Created on 17 de junio de 2024, 12:52
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

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
    void SetNombre(char* cad);
    void GetNombre(char *cad) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    virtual void lee(ifstream &file);
    virtual void imprime(ofstream &file);
    virtual void actualizaTotal(double pago);
};

#endif /* ALUMNO_H */

