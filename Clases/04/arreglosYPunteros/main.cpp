/* 
 * File:   main.cpp
 * Author: ivana
 *
 * Created on 26 de marzo de 2024, 02:51 PM
 */

#include <iostream>

using namespace std;

void asignarDatos(int * &p){
    int *array = new int[5]{10, 20, 30, 40, 50};
    p = array;
}

int main(int argc, char** argv) {

    int *parray = nullptr;
    asignarDatos(parray);
    
    for(int i=0; i<5; i++)
        cout << parray[i] << endl;
    
    delete[]parray;
    return 0;
}

