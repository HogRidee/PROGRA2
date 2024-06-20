/* 
 * File:   NPedido.h
 * Author: Ivan
 *
 * Created on 20 de junio de 2024, 17:49
 */

#ifndef NPEDIDO_H
#define NPEDIDO_H

#include <cstring>

class NPedido {
private:
    char *codigo;
    int cantidad;
    double peso;
public:
    NPedido();
    virtual ~NPedido();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(char* cad);
    void GetCodigo(char *cad) const;
};

#endif /* NPEDIDO_H */

