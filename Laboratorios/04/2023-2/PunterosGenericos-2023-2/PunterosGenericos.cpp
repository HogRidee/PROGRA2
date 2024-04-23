#include "PunterosGenericos.h"
#include "MuestraPunteros.h"

void cargaproductos(void *&productos){
    ifstream file("productos2.csv");
    if(not file.is_open()){
        cout << "ERROR: NO SE PUDO ABRIR EL ARCHIVO productos2.csv" << endl;
        exit(1);
    }
    int n = 0;
    void *producto, *buffer[200], **productosFinal;
    while(true){
        producto = leerProducto(file);
        if(file.eof()) break;
        buffer[n] = producto;
        n++;
    }
    productosFinal = new void*[n+1]{};
    for(int i = 0; i < n; i++)
        productosFinal[i] = buffer[i];
    productos = productosFinal;
    file.close();
}

void *leerProducto(ifstream &file){
    void **producto;
    double pre, *precio;
    char *codigo, *nombre, c, *tipo;
    tipo = new char;
    codigo = leerCadenaExacta(file, 10, ',');
    if(file.eof()) return nullptr;
    nombre = leerCadenaExacta(file, 200, ',');
    file >> pre >> c >> tipo;
    file.ignore();
    precio = new double;
    *precio = pre;
    producto = new void*[4]{};
    producto[0] = codigo;
    producto[1] = nombre;
    producto[2] = precio;
    producto[3] = tipo;
    return producto;
}

char *leerCadenaExacta(ifstream &file, int n, char c){
    char buffer[n], *cadena;
    file.getline(buffer, n, c);
    if(file.eof()) return nullptr;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

void cargaclientes(void *&clientes){
    ifstream file("clientes2.csv");
    if(not file.is_open()){
        cout << "NO SE PUDO ABRIR EL ARCHIVO Clientes2.csv" << endl;
        exit(1);
    }
    void **clientesFinal, *cliente, *buffer[200];
    int n = 0;
    while(true){
        cliente = leerCliente(file);
        if(file.eof()) break;
        buffer[n] = cliente;
        n++;
    }
    clientesFinal = new void*[n+1]{};
    for(int i = 0; i < n; i++)
        clientesFinal[i] = buffer[i];
    clientes = clientesFinal;
    file.close();
}

void *leerCliente(ifstream &file){
    void **cliente;
    int cod, *codigo;
    double linea, *lineaCredito;
    char *nombre, c, *descartado;
    file >> cod;
    if(file.eof()) return nullptr;
    file.get();
    nombre = leerCadenaExacta(file, 100, ',');
    descartado = leerCadenaExacta(file, 200, ',');
    file >> linea;
    codigo = new int;
    lineaCredito = new double;
    *codigo = cod;
    *lineaCredito = linea;
    cliente = new void*[4]{};
    cliente[0] = codigo;
    cliente[1] = nombre;
    cliente[2] = nullptr;
    cliente[3] = lineaCredito;
    return cliente;
}

void cargapedidos(void *&productos, void *&clientes){
    ifstream file("pedidos2.csv");
    if(not file.is_open()){
        cout << "ERROR: NO SE PUDO ABRIR EL ARCHIVO pedidos2.csv" << endl;
        exit(1);
    }
    int dni, cantidad, pos;
    char *codigo, c;
    while(true){
        codigo = leerCadenaExacta(file, 10, ',');
        if(file.eof()) break;
        file >> dni >> c >> cantidad;
        pos = buscarCliente(dni, clientes);
        if(pos != -1) cargarPedido(clientes, pos, codigo, productos, cantidad);
        file.ignore();
    }
    file.close();
}

int buscarCliente(int dni, void *clientes){
    void **cliente = (void**)clientes;
    void **aux;
    int *dniCliente;
    for(int i = 0; cliente[i]; i++){
        aux = (void**)cliente[i];
        dniCliente = (int*)(aux[0]);
        if(*dniCliente == dni) return i;
    }
    return -1;
}

void cargarPedido(void *&clientes, int pos, char* codigo, void *productos, 
        int cantidad){
    bool consumeCredito, hayLineaCredito;
    double total;
    consumeCredito = verificarSiConsumeCredito(codigo, productos);
    total = calcularTotal(codigo, productos, cantidad);
    if(consumeCredito){
        hayLineaCredito = verificarLineaCredito(clientes, pos, total);
        if(not hayLineaCredito) return;
        actualizarLineaCredito(clientes, pos, total);
    }
    cargarProducto(clientes, pos, codigo, productos, cantidad);
}

bool verificarSiConsumeCredito(char *codigo, void *productos){
    void **producto = (void**)productos;
    void **aux;
    char *cod, *tipo;
    for(int i = 0; producto[i]; i++){
        aux = (void **)producto[i];
        cod = (char*)(aux[0]);
        if(strcmp(cod, codigo) == 0){
            tipo = (char*)(aux[3]);
            if(strcmp(tipo, "S") == 0)
                return true;
            else
                return false;
        }
    }
    return false;
}

double calcularTotal(char *codigo, void *productos, int cantidad){
    double *prec, total;
    char *cod;
    void **producto = (void**)productos;
    void **aux;
    for(int i = 0; producto[i]; i++){
        aux = (void **)producto[i];
        cod = (char*)(aux[0]);
        if(strcmp(cod, codigo) == 0){
            prec = (double*)(aux[2]);
            total = *prec*cantidad;
            return total;
        }
    }
    return 0;
}

bool verificarLineaCredito(void *clientes, int pos, double total){
    double *linea;
    void **cliente = (void**)clientes;
    void **aux;
    aux = (void**)cliente[pos];
    linea = (double*)(aux[3]);
    if(*linea > total) return true;
    else return false;
}

void actualizarLineaCredito(void *&clientes, int pos, double total){
    double *linea;
    void **cliente = (void**)clientes;
    void **aux;
    aux = (void**)(cliente[pos]);
    linea = (double*)(aux[3]);
    *linea -= total;
}

void cargarProducto(void *&clientes, int pos, char* codigo, void *productos, 
        int cantidad);