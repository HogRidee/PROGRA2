#include "AsignacionDinamicaMemoriaExacta.h"

void lecturaDeProductos (const char *filename, char ***&productos, int *&stock, 
        double *&precios){
    ifstream file = abrirArchivoLectura(filename);
    productos = nullptr;
    stock = nullptr;
    precios = nullptr;
    int n = 0, cap = 0, buffStock;
    double buffPrecios;
    char *codigo, *nombre, c;
    while(true){
        codigo = leerCadena(file, ',');
        if(file.eof()) break;
        nombre = leerCadena(file, ',');
        file >> buffPrecios >> c >> buffStock;
        if(n == cap){
            cap += INCREMENTO;
            aumentarEspacios(stock, n , cap);
            aumentarEspacios(precios, n , cap);
        }
        stock[n-1] = buffStock;
        n++;
        cout << precios[0] << precios[1];
        break;
    }
    file.close();
}

void aumentarEspacios(double *&precios, int &n , int cap){
    double *aux;
    if(precios == nullptr){
        precios = new double[cap]{};
        n = 1;
    }
    else{
        aux = new double[cap]{};
        for(int i = 0; i < n; i++){
            aux[i] = precios[i];
        }
        delete[] precios;
        precios = aux;
    }
}

void aumentarEspacios(int *&stock, int &n , int cap){
    int *aux;
    if(stock == nullptr){
        stock = new int[cap]{};
        n = 1;
    }
    else{
        aux = new int[cap]{};
        for(int i = 0; i < n; i++){
            aux[i] = stock[i];
        }
        delete[] stock;
        stock = aux;
    }
}

char *leerCadena(ifstream &file, char delim){
    char buffer[100], *cadena;
    file.getline(buffer, 100, delim);
    if(file.eof()) return nullptr;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

ifstream abrirArchivoLectura(const char *filename){
    ifstream file(filename);
    if(!file.is_open()){
        cout << "NO SE PUDO ABRIR EL ARCHIVO " << filename << endl;
        exit(1);
    }
    return file;
}

void pruebaDeLecturaDeProductos (const char *filename, char ***productos, int *stock, 
        double *precios){
    
}