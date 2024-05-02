/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FlotaGenerica.h
 * Author: RODRIGO
 *
 * Created on 30 de abril de 2024, 23:37
 */

#ifndef FLOTAGENERICA_H
#define FLOTAGENERICA_H

void cargacamiones(void* &flota,int numcamiones,double pesomaximo,
        void* (*leedato)(ifstream&),double (*calculadato)(void*,void*,double,int&),const char* nomArch);
void generarPilaCamion(void* &pila);
void agregarNuevoPeso(void* camion,void* dato,double nuevopeso);
void push(void* pila,void* dato);
int pilavacia(void* pila);
void muestracamiones(void* flota,int numcamiones,void (*imprimedato)(ofstream&,void*,int),const char* nomArch);


#endif /* FLOTAGENERICA_H */
