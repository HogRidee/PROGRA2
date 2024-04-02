/* 
 * File:   main.cpp
 * Author: ivana
 *
 * Created on 2 de abril de 2024, 03:39 PM
 */

#include <iostream>
#include <cstring>

using namespace std;

struct Alumno{
    char nombre[20];
    char carrera[20];
};

const Alumno ALUMNO_NULO{"0", "0"};

void operator += (Alumno array[], Alumno obj){
    int i = 0;
    while(strcmp(array[i].nombre, "0") != 0){
        i++;
    }
    array[i] = obj;
    array[i+1] = ALUMNO_NULO;
}

ostream& operator << (ostream &os, const Alumno array[]){
    int i = 0;
    while(strcmp(array[i].nombre, "0") != 0){
        os << array[i].nombre << "-" << array[i].carrera << endl;
        i++;
    }
}

int main(int argc, char** argv) {

    Alumno alumnos[100];
    alumnos[0] = ALUMNO_NULO;
    Alumno al1{"Ana", "INF"};
    Alumno al2{"Mauro", "MEC"};
    alumnos += al1;
    alumnos += al2;
    //[0] : al1, [1] : al2, [2] = ALUMNO_NULO
    cout << alumnos << endl;
    
    return 0;
}

