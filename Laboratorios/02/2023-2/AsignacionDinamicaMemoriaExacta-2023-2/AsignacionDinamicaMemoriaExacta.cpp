#include "AsignacionDinamicaMemoriaExacta.h"

void lecturaDeProductos(const char *filename, char ***&productos, int *&stock, 
        double *&precios){
    ifstream file = abrirArchivoLectura(filename);
    char **bufferProductos[200];
    int n = 0, bufferStock[200];
    double bufferPrecios[200];
    while(true){
        bufferProductos[n] = leerProducto(file);
        if(file.eof()) break;
        file >> bufferPrecios[n];
        file.ignore();
        file >> bufferStock[n];
        file.ignore();
        n++;
    }
    productos = new char**[n+1];
    stock = new int[n];
    precios = new double[n];
    for(int i = 0; i < n; i++){
        stock[i] = bufferStock[i];
        precios[i] = bufferPrecios[i];
        productos[i] = bufferProductos[i];
    }
    productos[n] = bufferProductos[n]; // nullptr
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

char** leerProducto(ifstream &file){
    char *cadena, **dupla;
    cadena = leerCadenaExacta(file, 8, ',');
    if(file.eof()) return nullptr;
    dupla = new char*[2]; //codigo y nombre
    dupla[0] = cadena;
    dupla[1] = leerCadenaExacta(file, 150, ',');
    return dupla;
}

char* leerCadenaExacta(ifstream &file, int max, char delimitador){
    char buffer[max], *cadena;
    file.getline(buffer, max, delimitador);
    if(file.eof()) return nullptr;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

void pruebaDeLecturaDeProductos(const char *filename, char ***productos, 
        int *stock, double *precios){
    ofstream file = abrirArchivoEscritura(filename);
    char **aux;
    file << setw(35) << " " << "PRUEBA DE LECTURA DE PRODUCTOS" << endl;
    imprimirLinea('*', 100, file);
    file << fixed << setprecision(2);
    file << left << setw(10) << "CODIGO" << setw(4) << " ";
    file << left << setw(60) << "NOMBRE" << setw(4) << " ";
    file << right << setw(5) << "STOCK" << setw(4) << " ";
    file << right << setw(7) << "PRECIO" << setw(4) << endl;
    imprimirLinea('-', 100, file);
    for(int i = 0; productos[i] != nullptr; i++){
        aux = productos[i];
        file << left << setw(10) << aux[0] << setw(4) << " ";
        file << left << setw(60) << aux[1] << setw(4) << " ";
        file << right << setw(5) << stock[i] << setw(4) << " ";
        file << right << setw(7) << precios[i] << setw(4) << endl;
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

void lecturaDePedidos(const char *filename, int *fechaPedidos, 
        char ***codigoPedidos, int ***dniCantPedidos){
    ifstream file = abrirArchivoLectura(filename);
    int dni, cantidad, dd, mm, aaaa, fecha, posicion, bufferFechas[600], n = 0;
    int **bufferCantPedidos[600], numPedido[600];
    char *codigo, **bufferCodigoPedidos[600], c;
    while(true){
        codigo = leerCadenaExacta(file, 8, ',');
        if(file.eof()) break;
        file >> dni >> c >> cantidad >> c >> dd >> c >> mm >> c >> aaaa;
        file.ignore();
        fecha = aaaa*10000 + mm*100 + dd;
        posicion = buscarFecha(bufferFechas, fecha, n);
        if(posicion == -1){
            agregarFecha(bufferCantPedidos, bufferCodigoPedidos, bufferFechas, 
                    fecha, numPedido, n);
        }
    }
}

int buscarFecha(int *bufferFechas, int fecha, int &n){
    for(int i = 0; i < n; i++){
        if(bufferFechas[i] == fecha) return i;
    }
    return -1;
}

void pruebaDeLecturaDePedidos(const char *filename, int *fechaPedidos, 
        char ***codigoPedidos, int ***dniCantPedidos){
    
}