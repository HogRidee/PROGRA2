/* 
 * File:   Vehiculo.h
 * Author: Ivan
 *
 * Created on 4 de julio de 2024, 10:40
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <fstream>

using namespace std;

class Vehiculo {
private:
    int dni;
    string placa;
    double carga_maxima;
    double carga_actual;
public:
    Vehiculo();
    virtual ~Vehiculo();
    void SetCarga_actual(double carga_actual);
    double GetCarga_actual() const;
    void SetCarga_maxima(double carga_maxima);
    double GetCarga_maxima() const;
    void SetPlaca(string placa);
    string GetPlaca() const;
    void SetDni(int dni);
    int GetDni() const;
    void operator =(class Vehiculo *vehiculo);
    
    virtual void leer(ifstream &arch);
};

ostream & operator << (ostream );

#endif /* VEHICULO_H */

