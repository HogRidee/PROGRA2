#include "Pregunta02Examen01PunterosGenericos.h"

void cargarProductos(void *&productos, const char*filename){
    ifstream file(filename);
    if(not file.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    int n = 0;
    char *codigo;
    void *buffer[200];
    void **producto;
    while(true){
        codigo = leerCadena(file, 15, ',');
        if(file.eof()) break;
        buffer[n] = leerProducto(file, codigo); //utilizo asignación exacta
        n++;
    }
    producto = new void*[n+1]{};
    for(int i = 0; i < n; i++){
        void **dupla = new void*[2]{};
        dupla[0] = buffer[i];
        producto[i] = dupla;
    }
    productos = producto;
    qsort(productos, n, sizeof(void*), comparaCodigo);
    file.close();
}

void *leerProducto(ifstream &file, char *codigo){
    int *stock;
    double *prec;
    char *nombre, c;
    void **producto;
    stock = new int;
    prec = new double;
    nombre = leerCadena(file, 100, ',');
    file >> *prec >> c >> *stock;
    file.ignore();
    producto = new void*[4];
    producto[0] = codigo;
    producto[1] = nombre;
    producto[2] = prec;
    producto[3] = stock;
    return producto;
}

char *leerCadena(ifstream &file, int n, char c){
    char buffer[n], *cadena;
    file.getline(buffer, n, c);
    if(file.eof()) return nullptr;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

int comparaCodigo(const void *a, const void *b){
    void **ai = (void**)a;
    void **bi = (void**)b;
    void **regA = (void**)(ai[0]);
    void **regB = (void**)(bi[0]);
    char *codA = (char *)(regA[0]), *codB=(char *)(regB[0]);
    cout << *codA << " " << *codB << endl;
    return strcmp(codA,codB);
}

void pruebaDeCargaDeProductos(void *productos){
    ofstream file("ReporteProductos.txt");
    if(not file.is_open()){
        cout << "ERROR: No se pudo abrir el archivo ReporteProductos.txt" << endl;
        exit(1);
    }
    void **producto = (void**)productos;
    imprimirCabecera(file);
    for(int i = 0; producto[i]; i++){
        void **aux = (void**)producto[i];
        void **aux2 = (void**)aux[0];
        file << left << setw(10) << (char*)aux2[0];
        file << left << setw(50) << (char*)aux2[1];
        file << right << setw(10) << *(double*)aux2[2];
        file << right << setw(13) << *(int*)aux2[3] << endl;
    }
    file.close();
}

void imprimirCabecera(ofstream &file){
    file << left << setw(15) << "CÓDIGO";
    file << left << setw(50) << "DESCRIPCIÓN";
    file << left << setw(15) << "PRECIO";
    file << left << setw(15) << "STOCK" << endl;
    imprimirLinea(file, 100, '=');
}

void imprimirLinea(ofstream &file, int n, char c){
    for(int i = 0; i < n; i++)
        file.put(c);
    file.put('\n');
}