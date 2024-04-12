/* 
 * File:   funciones.h
 * Author: ivana
 *
 * Created on 5 de abril de 2024, 04:00 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <fstream>
#include <cstring>

#define INCREMENTO 5

using namespace std;

char *leerCadena(ifstream &file, char delim){
    char buffer[200];
    file.getline(buffer, 200, delim);
    char *cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

char **separarCursos(char *bufferCursos){
    char *bufferCodigoCursos[15];
    int n = 0;
    char *ptrCadena = strtok(bufferCursos, ",");
    while(ptrCadena != nullptr){
        bufferCodigoCursos[n] = ptrCadena;
        ptrCadena = strtok(nullptr, ",");
        n++;
    }
    char **codigoCursos = new char*[n+1];
    for (int i = 0; i < n; i++){
        codigoCursos[i] = bufferCodigoCursos[i];
    }
    codigoCursos[n] = nullptr;
    return codigoCursos;
}

void incrementarEspacio(char ***&parray, int n, int cap){
    if(parray == nullptr){
        parray = new char**[cap+1]{};
    }
    else{
        char ***aux = new char**[cap+1]{};
        for(int i = 0; i < n; i++){
            aux[i] = parray[i];
        }
        delete[] parray;
        parray = aux;
    }
}

void incrementarEspacio(char **&parray, int n, int cap){
    if(parray == nullptr){
        parray = new char*[cap+1]{};
    }
    else{
        char **aux = new char*[cap+1]{};
        for(int i = 0; i < n; i++){
            aux[i] = parray[i];
        }
        delete[] parray;
        parray = aux;
    }
}

void leerDatos(const char *filename, char **&codigos, char **&nombres, 
        char ***&cursos){
    ifstream file(filename);
    if(!file.is_open()) exit(0);
    int n = 0, cap = 0;
    char *tnombre, *tcodigo, *tcursos;
    while(true){
        tcodigo = leerCadena(file, ',');
        if(file.eof()) break;
        tnombre = leerCadena(file, ',');
        tcursos = leerCadena(file, '\n');
        if(n == cap){
            cap += INCREMENTO;
            incrementarEspacio(codigos, n, cap);
            incrementarEspacio(nombres, n, cap);
            incrementarEspacio(cursos, n, cap);
        }
        codigos[n] = tcodigo;
        nombres[n] = tnombre;
        cursos[n] = separarCursos(tcursos);
        n++;
    }
    file.close();
}

void mostrarDatos(char **codigos, char **nombres, char ***cursos){
    int j;
    for(int i = 0; codigos[i] != nullptr; i++){
        cout << codigos[i] << "-" << nombres[i] << ":" << endl << "  ";
        for (j = 0; cursos[i][j] != nullptr; j++){
            cout << cursos[i][j] << " ";
        }
        cout << "Numero de cursos: " << j;
        cout << endl;
    }
}

#endif /* FUNCIONES_H */

