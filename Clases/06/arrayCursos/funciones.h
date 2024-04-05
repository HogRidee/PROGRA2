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

void leerDatos(const char *filename, char **&codigos, char **&nombres, 
        char ***&cursos){
    ifstream file(filename);
    if(!file.is_open()) exit(0);
    char *bufferCodigos[50];
    char *bufferNombres[50];
    char *bufferCursos[50];
    int n = 0;
    while(true){
        bufferCodigos[n] = leerCadena(file, ',');
        if(file.eof()) break;
        bufferNombres[n] = leerCadena(file, ',');
        bufferCursos[n] = leerCadena(file, '\n');
        n++;
    }
    codigos = new char*[n+1];
    nombres = new char*[n+1];
    cursos = new char**[n+1];
    for(int i = 0; i < n; i++){
        codigos[i] = bufferCodigos[i];
        nombres[i] = bufferNombres[i];
        cursos[i] = separarCursos(bufferCursos[i]);
        //TODO: split a buffer de cursos[i]
    }
    codigos[n] = nullptr;
    nombres[n] = nullptr;
    cursos[n] = nullptr;
    
    file.close();
}

void mostrarDatos(char **codigos, char **nombres, char ***cursos){
    for(int i = 0; codigos[i] != nullptr; i++){
        cout << codigos[i] << "-" << nombres[i] << ":" << endl << "  ";
        for (int j = 0; cursos[i][j] != nullptr; j++){
            cout << cursos[i][j] << "-";
        }
        cout << endl;
    }
}

#endif /* FUNCIONES_H */

