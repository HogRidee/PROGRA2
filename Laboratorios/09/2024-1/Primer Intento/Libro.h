/* 
 * File:   Libro.h
 * Author: Ivan
 *
 * Created on 7 de julio de 2024, 12:56
 */

#ifndef LIBRO_H
#define LIBRO_H

#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

class Libro {
private:
    char *nombre;
    int paginas;
    double peso;
public:
    Libro();
    virtual ~Libro();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetPaginas(int paginas);
    int GetPaginas() const;
    void SetNombre(char* cad);
    void GetNombre(char *cad) const;
    
    virtual void leer(ifstream &arch);
    virtual void imprimir(ofstream &arch);
};

#endif /* LIBRO_H */

