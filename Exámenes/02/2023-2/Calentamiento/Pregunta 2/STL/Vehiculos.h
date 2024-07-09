/* 
 * File:   Vehiculos.h
 * Author: Ivan
 *
 * Created on 9 de julio de 2024, 8:16
 */

#ifndef VEHICULOS_H
#define VEHICULOS_H

#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class Vehiculos {
private:
    int dni;
    string placa;
    double carga_maxima;
    double carga_actual;
public:
    Vehiculos();
    Vehiculos(const Vehiculos& orig);
    virtual ~Vehiculos();
    void SetCarga_actual(double carga_actual);
    double GetCarga_actual() const;
    void SetCarga_maxima(double carga_maxima);
    double GetCarga_maxima() const;
    void SetPlaca(string placa);
    string GetPlaca() const;
    void SetDni(int dni);
    int GetDni() const;
    
    virtual void leer(ifstream &arch);
    virtual void mostrar(ofstream &arch);
    virtual bool insertar(class Pedido pedido);
};

#endif /* VEHICULOS_H */

