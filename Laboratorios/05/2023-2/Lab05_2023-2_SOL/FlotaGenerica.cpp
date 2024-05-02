/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FlotaGenerica.cpp
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
#include "FlotaGenerica.h"
#include "PilaConEnteros.h"
#include "PilaConRegistros.h"

void cargacamiones(void* &flota,int numcamiones,double pesomaximo,
        void* (*leedato)(ifstream&),double (*calculadato)(void*,void*,double,int&),const char* nomArch){
    ifstream arch(nomArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    double nuevopeso;
    int indCamion = 0,actual;
    flota = new void*[numcamiones+1]; //para el nullptr
    void *dato,**lflota = (void**)flota;
    
    for(int i=0;i<numcamiones;i++)
        generarPilaCamion(lflota[i]);
    lflota[numcamiones] = nullptr;
    
    while(true){
        dato = leedato(arch);
        if(dato == nullptr)break;
        actual = 1;
        nuevopeso = calculadato(lflota[indCamion],dato,pesomaximo,actual);
        
        if(actual == 0){  //no se suma nada porque se excede el peso
            if(nuevopeso <= pesomaximo){ //si excede el peso maximo no nos sirve ese pedido porque no entra en ningun camion
                indCamion++;
                if(indCamion == numcamiones)break;
                agregarNuevoPeso(lflota[indCamion],dato,nuevopeso); 
            }
        }else{
            agregarNuevoPeso(lflota[indCamion],dato,nuevopeso); 
        }
    }
}

void generarPilaCamion(void* &pila){
    pila = new void*[2];
    void **lpila = (void**)pila;
    double *pesoCamion = new double;
    *pesoCamion = 0.0;
    lpila[0] = nullptr;
    lpila[1] = pesoCamion;
}

void agregarNuevoPeso(void* camion,void* dato,double nuevopeso){
    void **lcamion = (void**)camion;
    double *pesoCamion;
    pesoCamion = (double*)lcamion[1];
    *pesoCamion = *pesoCamion + nuevopeso;
    push(camion,dato);
}

void push(void* pila,void* dato){
    void **lpila = (void**)pila;
    void **nuevo = new void*[2];    
    nuevo[1] = dato;
    //nuevo[0] = nullptr;
    nuevo[0] = lpila[0];
    lpila[0] = nuevo;
}

int pilavacia(void* pila){
    void **lpila = (void**)pila;
    if(lpila[0]==nullptr)return 1;
    else return 0;
}

void muestracamiones(void* flota,int numcamiones,void (*imprimedato)(ofstream&,void*,int),const char* nomArch){
    ofstream arch(nomArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    arch.precision(2);
    arch<<fixed;

    void **lflota = (void**)flota;
    for(int i=0;lflota[i]!=nullptr;i++){
        imprimedato(arch,lflota[i],i+1);
    }
}