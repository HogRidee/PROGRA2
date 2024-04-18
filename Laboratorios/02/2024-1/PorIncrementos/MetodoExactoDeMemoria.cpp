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
        if(nDatos == capacidad)
            aumentarEspacios(libros, stock, nDatos, capacidad);
        cargarLibros(libros, stock, nDatos, codigo, titulo, nombre, bufferStock);
        nDatos++;
        file.ignore();
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

void aumentarEspacios(char ***&libros, int **&stock, int &nDatos, int &capacidad){
    capacidad += INCREMENTO;
    int **auxStock;
    char ***auxLibros;
    if(libros == nullptr){
        libros = new char**[capacidad]{};
        stock = new int*[capacidad]{};
        nDatos = 1;
    }
    else{
        auxLibros = new char**[capacidad]{};
        auxStock = new int*[capacidad]{};
        for(int i = 0; i < nDatos; i++){
            auxLibros[i] = libros[i];
            auxStock[i] = stock[i];
        }
        delete[] libros;
        delete[] stock;
        libros = auxLibros;
        stock = auxStock;
    }
}

void cargarLibros(char ***&libros, int **&stock, int nDatos, char *codigo, 
        char *titulo, char *nombre, int bufferStock){
    int *stockListo;
    char **libro;
    libro = new char*[3];
    stockListo = new int[2];
    libro[0] = new char[strlen(codigo)+1];
    libro[1] = new char[strlen(titulo)+1];
    libro[2] = new char[strlen(nombre)+1];
    strcpy(libro[0], codigo);
    strcpy(libro[1], titulo);
    strcpy(libro[2], nombre);
    stockListo[0] = bufferStock;
    stockListo[1] = 0;
    libros[nDatos-1] = libro;
    stock[nDatos-1] = stockListo;
    delete[] codigo;
    delete[] titulo;
    delete[] nombre;
}

void pruebaDeLecturaDeLibros (const char *filename, char ***libros, int **stock){
    ofstream file(filename);
    if(not file.is_open()){
        cout << "ERROR: NO SE PUDO ABRIR EL ARCHIVO: " << filename << endl;
        exit(1);
    }
    imprimirEncabezado(file);
    int *aux;
    char **libro;
    for(int i = 0; libros[i]; i++){
        libro = libros[i];
        aux = stock[i];
        file << left << setw(15) << libro[0] << setw(60) << libro[1] << setw(28) << 
                libro[2];
        file << right << setw(10) << aux[0] << setw(23) << aux[1] << endl;
    }
}

void imprimirEncabezado(ofstream &file){
    file << setw(60) << " " << "REPORTE DE LIBROS" << endl;
    imprimirLinea(file, '=', 150);
    file << left << setw(28) << "CODIGO" << setw(52) << "TITULO" << setw(28) <<
            "AUTOR" << setw(18) << "STOCK" << setw(28) << "CANTIDAD NO ATENDIDA"
            << endl;
    imprimirLinea(file, '-', 150);
}

void imprimirLinea(ofstream &file, char c, int n){
    for(int i = 0; i < n; i++){
        file.put(c);
    }
    file.put('\n');
}

void atencionDePedidos (const char *filename, char ***libros, int **&stock, 
        int **&pedidosClientes, char ***&pedidosLibros, bool **&pedidosAtendidos){
    ifstream file(filename);
    if(not file.is_open()){
        cout << "ERROR: NO SE PUDO ABRIR EL ARCHIVO " << filename << endl;
        exit(1);
    }
    pedidosClientes = nullptr;
    pedidosLibros = nullptr;
    pedidosAtendidos = nullptr;
    int nDatos = 0, capacidad = 0, dni, codigo;
    char c;
    while(true){
        file >> codigo;
        if(file.eof()) break;
        file >> c >> dni;
        if(nDatos == capacidad)
            incrementarEspacio(pedidosLibros, pedidosAtendidos, nDatos, capacidad);
        cargarPedidos(file, pedidosLibros[nDatos-1], pedidosAtendidos[nDatos-1], 
                libros, stock);
        nDatos++;
    }
    file.close();
}

void incrementarEspacio(char ***&pedidosLibros, bool **&pedidosAtendidos, 
        int &nDatos, int &capacidad){
    bool **auxAtendidos;
    char ***auxPedidos;
    capacidad += INCREMENTO;
    if(pedidosLibros == nullptr){
        pedidosLibros = new char**[capacidad]{};
        pedidosAtendidos = new bool*[capacidad]{};
        nDatos = 1;
    }
    else{
        auxPedidos = new char**[capacidad]{};
        auxAtendidos = new bool*[capacidad]{};
        for(int i = 0; pedidosLibros[i]; i++){
            auxPedidos[i] = pedidosLibros[i];
            auxAtendidos[i] = pedidosAtendidos[i];
        }
        delete[] pedidosLibros;
        delete[] pedidosAtendidos;
        pedidosLibros = auxPedidos;
        pedidosAtendidos = auxAtendidos;
    }
}

void cargarPedidos(ifstream &file, char **&pedidosLibros, bool *&pedidosAtendidos, 
        char ***libros, int **&stock){
    int nDatos = 0, capacidad = 0;
    char codigo[10];
    while(true){
        if(nDatos == capacidad)
            incrementarEspacio(pedidosLibros, pedidosAtendidos, nDatos, capacidad);
        file >> codigo;
        cargarCodigo(codigo, pedidosLibros[nDatos-1], pedidosAtendidos[nDatos-1], 
                libros, stock);
        if(file.get() == '\n') break;
        nDatos++;
    }
}

void incrementarEspacio(char **&pedidosLibros, bool *&pedidosAtendidos, 
        int &nDatos, int &capacidad){
    bool *auxAtendidos;
    char **auxPedidos;
    capacidad += INCREMENTO;
    if(pedidosLibros == nullptr){
        pedidosLibros = new char*[capacidad]{};
        pedidosAtendidos = new bool[capacidad]{};
        nDatos = 1;
    }
    else{
        auxPedidos = new char*[capacidad]{};
        auxAtendidos = new bool[capacidad]{};
        for(int i = 0; pedidosLibros[i]; i++){
            auxPedidos[i] = pedidosLibros[i];
            auxAtendidos[i] = pedidosAtendidos[i];
        }
        delete[] pedidosLibros;
        delete[] pedidosAtendidos;
        pedidosLibros = auxPedidos;
        pedidosAtendidos = auxAtendidos;
    }
}

void cargarCodigo(char *codigo, char *&pedidosLibros, bool &pedidosAtendidos, 
        char ***libros, int **&stock){
    int posicion, *stockLibro;
    pedidosLibros = new char[strlen(codigo)+1];
    strcpy(pedidosLibros, codigo);
    posicion = buscarLibro(libros, codigo);
    if(posicion != -1){
        stockLibro = stock[posicion];
        if(stockLibro[0] > 0){
            pedidosAtendidos = true;
            stockLibro[0]--;
        }
        else{
            pedidosAtendidos = false;
            stockLibro[1]++;
        }
    }
}

int buscarLibro(char ***libros, char *codigo){
    char **libro;
    char *codigoLibro;
    for(int i = 0; libros[i]; i++){
        libro = libros[i];
        codigoLibro = libro[0];
        if(strcmp(codigoLibro, codigo) == 0){
            return i;
        }
    }
    return -1;
}