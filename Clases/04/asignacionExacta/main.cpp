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

int main(int argc, char** argv) {

    int *parray = nullptr;
    int n;
    leerDatosArchivo(parray, n);
    
    for (int i = 0; i < n; i++){
        cout << "\t" << parray[i] << endl;
    }
    
    return 0;
}

