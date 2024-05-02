/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: RODRIGO
 *
 * Created on 30 de abril de 2024, 23:35
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



/*
 * 
 */
int main(int argc, char** argv) {
    int numcamiones;
    double pesomaximo;
    void *flota;
    
    numcamiones = 5,pesomaximo = 10;
    cargacamiones(flota,numcamiones,pesomaximo,leenumero,calculanumero,"numeros.txt");
    qsort(flota,numcamiones,sizeof(void*),cmpnumero);
    muestracamiones(flota,numcamiones,imprimenumero,"reportenum.txt");
    
    numcamiones = 100,pesomaximo = 400;
    cargacamiones(flota,numcamiones,pesomaximo,leeregistro,calcularegistro,"Pedidos3.csv");
    qsort(flota,numcamiones,sizeof(void*),cmpnumero);
    muestracamiones(flota,numcamiones,imprimeregistro,"reporteregistro.txt");
    
    
    
    
    
    
    return 0;
}

