/* 
 * File:   main.cpp
 * Author: ivana
 *
 * Created on 2 de abril de 2024, 02:44 PM
 */

#include <iostream>
#include <fstream>

#define INCREMENTO 5

using namespace std;

void incrementarEspacio(int *&parray, int n, int &capacidad){
    capacidad += INCREMENTO;
    if(parray == nullptr){
        parray = new int[capacidad];
    }
    else{
        int *aux = new int[capacidad];
        for(int i = 0; i < n; i++){
            aux[i] = parray[i];
        }
        delete[] parray;
        parray = aux;
    }
}

void leerDatosArchivo(int *&parray, int &n){
    ifstream file("datos.txt");
    n = 0;
    int capacidad = 0;
    int dato;
    while(true){
        if(file.eof()) break;
        file >> dato;
        if(n == capacidad) incrementarEspacio(parray, n, capacidad);
        parray[n] = dato;
        n++;
    }
    
    file.close();
}

void test(){
    int *parray = nullptr;
    int n;
    leerDatosArchivo(parray, n);
    for(int i = 0; i < n; i++){
        cout << parray[i] << endl;
    }
}

int main(int argc, char** argv) {
    test();
    return 0;
}

