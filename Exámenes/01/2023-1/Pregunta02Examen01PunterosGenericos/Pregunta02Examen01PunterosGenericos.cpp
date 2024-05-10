#include "Pregunta02Examen01PunterosGenericos.h"

void cargarProductos(void *&productos, const char*filename){
    ifstream file(filename);
    if(not file.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    int n = 0, cap = 0;
    void **producto, *infoProductos;
    producto = new void*[2]{};
    while(true){
        infoProductos = leerProducto(file);
        if(file.eof()) break;
        break;
        n++;
    }
    productos = producto;
    file.close();
}

void *leerProducto(ifstream &file){
    char *codigo;
    void **producto;
}

char *leerCadena(ifstream &file, int n, int c){
    
}

void pruebaDeCargaDeProductos(void *productos){
    
}