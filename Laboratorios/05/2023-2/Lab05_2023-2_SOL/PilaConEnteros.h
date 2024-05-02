/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PilaConEnteros.h
 * Author: RODRIGO
 *
 * Created on 30 de abril de 2024, 23:36
 */

#ifndef PILACONENTEROS_H
#define PILACONENTEROS_H


void* leenumero(ifstream& arch);
double calculanumero(void* pilacamion,void* dato,double pesomaximom,int &actual);
void imprimenumero(ofstream& arch,void* pila,int i);
int cmpnumero(const void* a,const void*b);


#endif /* PILACONENTEROS_H */
