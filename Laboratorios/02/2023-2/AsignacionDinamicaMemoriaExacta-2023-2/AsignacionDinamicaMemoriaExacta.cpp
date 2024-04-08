#include "AsignacionDinamicaMemoriaExacta.h"

void lecturaDeProductos(const char *filename, char ***&productos, int *&stock, 
        double *&precios){
    ifstream file = abrirArchivoLectura(filename);
    char *bufferCodigos[200], *bufferNombres[200];
    int n = 0, bufferStock[200];
    double bufferPrecios[200];
    while(true){
        bufferCodigos[n] = leerCadena(file, ',');
        if(file.eof()) break;
        bufferNombres[n] = leerCadena(file, ',');
        file >> bufferPrecios[n];
        file.ignore();
        file >> bufferStock[n];
        file.ignore();
        n++;
    }
    stock = new int[n+1];
    precios = new double[n+1];
    productos = new char**[n+1];
    for(int i = 0; i < n; i++){
        stock[i] = bufferStock[i];
        precios[i] = bufferPrecios[i];
        productos[i] = new char*[2];
        productos[i][0] = bufferCodigos[i];
        productos[i][1] = bufferNombres[i];
    }
    stock[n] = -1;
    precios[n] = -1;
    productos[n] = nullptr;
    file.close();
}

ifstream abrirArchivoLectura(const char *filename){
    ifstream file(filename);
    if(!file.is_open()){
        cout << "ERROR: NO SE PUDO ABRIR EL ARCHIVO " << filename << endl;
        exit(1);
    }
    return file;
}

char* leerCadena(ifstream &file, char delimitador){
    char buffer[200];
    file.getline(buffer, 200, delimitador);
    char *cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

void pruebaDeLecturaDeProductos(const char *filename, char ***productos, 
        int *stock, double *precios){
    ofstream file = abrirArchivoEscritura(filename);
    file << setw(35) << " " << "PRUEBA DE LECTURA DE PRODUCTOS" << endl;
    imprimirLinea('-', 100, file);
    for(int i = 0; productos[i] != nullptr; i++){
        file << left << setw(10) << productos[i][0] << setw(4) << " ";
        file << left << setw(60) << productos[i][1] << setw(4) << " ";
        file << right << setw(5) << stock[i] << setw(4) << " " << endl;
    }
    file.close();
}

ofstream abrirArchivoEscritura(const char *filename){
    ofstream file(filename);
    if(!file.is_open()){
        cout << "ERROR: NO SE PUDO ABRIR EL ARCHIVO " << filename << endl;
        exit(1);
    }
    return file;
}

void imprimirLinea(char c, int n, ofstream &file){
    for(int i = 0; i < n; i++){
        file.put(c);
    }
    file.put('\n');
}