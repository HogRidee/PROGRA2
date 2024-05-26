/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: Ivan
 *
 * Created on 26 de mayo de 2024, 9:48
 */

#ifndef ALUMNO_H
#define ALUMNO_H

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
    void SetNombre(char* nombre);
    char* GetNombre() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
};

#endif /* ALUMNO_H */

