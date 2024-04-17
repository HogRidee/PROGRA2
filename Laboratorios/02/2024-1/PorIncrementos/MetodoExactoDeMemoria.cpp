#include "MetodoExactoDeMemoria.h"

void lecturaDeLibros (const char *filename, char ***&libros, int **&stock){
    ifstream file(filename);
    if(not file.is_open()){
        cout << "ERROR: NO PUDO ABRIRSE EL ARCHIVO " << filename << endl;
        exit(1);
    }
    libros = nullptr;
    stock = nullptr;
    int bufferStock, nDatos = 0, capacidad = 0;
    double precio;
    char *codigo, *titulo, *nombre, c;
    while(true){
        codigo = leerCadena(file, 10, ',');
        if(file.eof()) break;
        titulo = leerCadena(file, 100, ',');
        nombre = leerCadena(file, 100, ',');
        file >> bufferStock >> c >> precio;
        if(nDatos == capacidad){
            aumentarEspacios()
        }
    }
    file.close();
}

char *leerCadena(ifstream &file, int n, char c){
    char buffer[n], *cadena;
    file.getline(buffer, n, c);
    if(file.eof()) return nullptr;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

void pruebaDeLecturaDeLibros (const char *filename, char ***libros, int **stock){
    
}