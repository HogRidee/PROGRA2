/* 
 * File:   Vehiculo.h
 * Author: Ivan
 *
 * Created on 6 de julio de 2024, 13:41
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class Vehiculo {
private:
    int dni;
    string placa;
    double carga_maxima;
    double carga_actual;
public:
    Vehiculo();
    Vehiculo(const Vehiculo& orig);
    virtual ~Vehiculo();
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

#endif /* VEHICULO_H */

