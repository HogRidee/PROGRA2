/* 
 * File:   Vehiculo.h
 * Author: Ivan
 *
 * Created on 20 de junio de 2024, 17:54
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include <cstring>

class Vehiculo {
private:
    int cliente;
    char *placa;
    double maxcarga;
    double actcarga;
public:
    Vehiculo();
    virtual ~Vehiculo();
    void SetActcarga(double actcarga);
    double GetActcarga() const;
    void SetMaxcarga(double maxcarga);
    double GetMaxcarga() const;
    void SetPlaca(char* cad);
    void GetPlaca(char *cad) const;
    void SetCliente(int cliente);
    int GetCliente() const;
};

#endif /* VEHICULO_H */

