#include "FlotaGenerica.h"

void *leenumero(ifstream &file){
    int d, *dato;
    file >> d;
    if(file.eof()) return nullptr;
    dato = new int;
    *dato = d;
    return dato;
}

int calculanumero(void *dato){
    
}

void imprimenumero(void *dato){
    int *peso = (int*)dato;
    cout << setw(6) << *peso;
}

int cmpnumero(const void* a,const void*b){
    void **ai = (void**)a;
    void **bi = (void**)b;
    
    void **camionA = (void**)*ai;
    void **camionB = (void**)*bi;
    
    int *pesoA = (int*)camionA[1];
    int *pesoB = (int*)camionB[1];
       
    return *pesoB - *pesoA;
}