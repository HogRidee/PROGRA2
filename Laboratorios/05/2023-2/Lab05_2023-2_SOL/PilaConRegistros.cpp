/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   PilaConRegistros.cpp
 * Author: RODRIGO
 * 
 * Created on 30 de abril de 2024, 23:37
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PilaConRegistros.h"


void* leeregistro(ifstream& arch){
    double peso,*ptrPeso;
    char *codProd,c;
    int dni,cantidad,*ptrCant;
    void **registro;
    codProd = leerCadenaExacta(arch,',');
    if(arch.eof())return nullptr;
    registro = new void*[3];
    arch>>dni>>c>>cantidad>>c>>peso;
    arch.get();
    
    ptrCant = new int;
    ptrPeso = new double;

    *ptrPeso = peso;
    *ptrCant = cantidad;
    
    registro[0] = codProd;
    registro[1] = ptrCant;
    registro[2] = ptrPeso;
    
    return registro;
}

double calcularegistro(void* pilacamion,void* dato,double pesomaximo,int &actual){
    void **lpilacamion = (void**)pilacamion;
    
    void **ldato = (void**)dato;
    int *cantidad = (int*)ldato[1];
    double *pesoActual,*pesoNuevo = (double*)ldato[2]; 
    pesoActual = (double*)lpilacamion[1];
    
    if(*pesoActual + (*pesoNuevo)*(*cantidad) > pesomaximo) actual = 0;
    
    return (*pesoNuevo)*(*cantidad);
}

char* leerCadenaExacta(ifstream& arch,char c){
    int longitud;
    char cadena[200],*ptrCadena;
    
    arch.getline(cadena,200,c);
    if(arch.eof())return nullptr;
    
    longitud = strlen(cadena);
    ptrCadena = new char[longitud+1];
    
    strcpy(ptrCadena,cadena);
    return ptrCadena;
}

void imprimeregistro(ofstream& arch,void* pila,int i){
    void **lpila = (void**)pila;
    
    double *pesoTotal = (double*)lpila[1];
    
    void **dato;
    
    char *codigo;
    int *cant;
    double *peso;
    
    arch<<left<<"Camion   "<<i<<setw(8)<<":"<<setw(10)<<"Peso"<<setw(10)<<*pesoTotal<<endl;
    
    if(lpila[0]!=nullptr){
        arch<<endl;
        void **p =(void**)lpila[0];
        while(p!=nullptr){
            dato = (void**)p[1];
            codigo = (char*)dato[0];
            cant = (int*)dato[1];
            peso = (double*)dato[2];

            arch<<left<<setw(15)<<" "<<setw(9)<<codigo<<right<<setw(5)<<*cant<<setw(10)<<*peso<<endl;
            p = (void**)p[0];
        }
    }
    
    arch<<endl;
}



