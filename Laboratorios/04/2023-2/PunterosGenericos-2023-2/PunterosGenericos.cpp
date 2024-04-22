#include "PunterosGenericos.h"
#include "MuestraPunteros.h"

void cargaproductos(void *&productos){
    ifstream file("productos2.csv");
    if(not file.is_open()){
        cout << "ERROR: NO SE PUDO ABRIR EL ARCHIVO productos2.csv" << endl;
        exit(1);
    }
    int n = 0;
    while(true){
        if(file.eof()) break;
        n++;
    }
    file.close();
}

void cargaclientes(void *&clientes){
    
}