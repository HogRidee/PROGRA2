/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   PilaConEnteros.cpp
 * Author: RODRIGO
 * 
 * Created on 30 de abril de 2024, 23:36
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PilaConEnteros.h"


void* leenumero(ifstream& arch){
    double num,*ptrNum;
    arch>>num;
    if(arch.eof())return nullptr;
    ptrNum = new double;
    *ptrNum = num;
    return ptrNum;
}

double calculanumero(void* pilacamion,void* dato,double pesomaximo,int &actual){
    void **lpilacamion = (void**)pilacamion;
    double *pesoActual,*pesoNuevo = (double*)dato;
    pesoActual = (double*)lpilacamion[1];
    
    if(*pesoActual + *pesoNuevo > pesomaximo) actual = 0;
    
    return *pesoNuevo;
}

void imprimenumero(ofstream& arch,void* pila,int i){
    void **lpila = (void**)pila;
    double *pesoTotal = (double*)lpila[1];
    double *peso;
    arch<<left<<"Camion   "<<i<<setw(8)<<":"<<setw(10)<<"Peso"<<setw(10)<<*pesoTotal<<endl;
    
    void **p = (void**)lpila[0];
    
    while(p!=nullptr){
        peso = (double*)p[1];
        arch<<left<<*peso<<endl;
        p = (void**)p[0];
    }
}

int cmpnumero(const void* a,const void*b){
    void **la = (void**)a;
    void **lb = (void**)b;
    
    void **camionA = (void**)*la;
    void **camionB = (void**)*lb;
    
    double *pesoA = (double*)camionA[1];
    double *pesoB = (double*)camionB[1];
    
    if(*pesoB - *pesoA > 0.0)return 1;
    else if(*pesoB - *pesoA == 0.0)return 0;
    else return -1;

    //return *pesoB - *pesoA;
}