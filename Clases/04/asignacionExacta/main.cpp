/* 
 * File:   main.cpp
 * Author: ivana
 *
 * Created on 26 de marzo de 2024, 03:23 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

void leerDatosArchivo(int *&parray, int &n){
    ifstream file("datos.txt");
    int buffer[100];
    n = 0;
    while(true){
        if(file.eof()) break;
        file >> buffer[n];
        n++;
    }
    parray = new int[n];
    for (int i = 0; i <= n; i++){
        parray[i] = buffer[i];
    }
    file.close();
}

void leerDatosArchivo(int *&parray){
    ifstream file("datos.txt");
    int buffer[100];
    int n = 0;
    while(true){
        if(file.eof()) break;
        file >> buffer[n];
        n++;
    }
    parray = new int[n];
    for (int i = 0; i <= n; i++){
        parray[i] = buffer[i];
    }
    parray[n] = 0;
    file.close();
}

void leerDatos(int *&parray, int &n){
    int buffer[100];
    n = 0;
    while(true){
        cin >> buffer[n];
        if(cin.eof()) break;
        n++;
    }
    parray = new int[n];
    for (int i = 0; i < n; i++){
        parray[i] = buffer[i];
    }
}

void test1(){
    int *parray = nullptr;
    int n;
    leerDatosArchivo(parray, n);
    //MOSTRAR
}

void test2(){
    int *parray = nullptr;
    leerDatosArchivo(parray);
    for (int i = 0; parray[i] != 0; i++){
        cout << "\t" << parray[i] << endl;
    }
}

int main(int argc, char** argv) {

    test2();
    
    return 0;
}

