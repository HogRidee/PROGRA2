#include "PunterosGenericos.h"
#include "MuestraPunteros.h"

void cargaproductos(void *&productos){
    ifstream file("Productos2.csv");
    if(not file.is_open()){
        cout << "ERROR: No se pudo abrir el archivo productos2.csv" << endl;
        exit(1);
    }
    int n = 0;
    char *codigo;
    void **producto;
    void *buffer[200];
    while(true){
        codigo = leerCadena(file, 10, ',');
        if(file.eof()) break;
        buffer[n] = leerProducto(file, codigo); 
        n++;
    }
    producto = new void*[n+1]{};
    for(int i = 0; i < n; i++)
        producto[i] = buffer[i];
    productos = producto;
    file.close();
}

char *leerCadena(ifstream &file, int n, char c){
    char *cadena, buffer[n];
    file.getline(buffer, n, c);
    if(file.eof()) return nullptr;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

void *leerProducto(ifstream &file, char *codigo){
    double *prec;
    char *nombre, c, *tipo;
    void **producto;
    producto = new void*[4]{};
    prec = new double;
    tipo = new char;
    nombre = leerCadena(file, 100, ',');
    file >> *prec >> c >> *tipo;
    file.ignore();
    producto[0] = codigo; 
    producto[1] = nombre;
    producto[2] = prec;
    producto[3] = tipo;
    return producto;
}

void cargaclientes(void *&clientes){
    ifstream file("clientes2.csv");
    if(not file.is_open()){
        cout << "ERROR: No se pudo abrir el archivo clientes2.csv" << endl;
        exit(1);
    }
    int dni, n = 0;
    void **cliente, *buffer[200];
    while(true){
        file >> dni;
        if(file.eof()) break;
        buffer[n] = leerCliente(file, dni);
        n++;
    }
    cliente = new void*[n+1]{};
    for(int i = 0; i < n; i++)
        cliente[i] = buffer[i];
    clientes = cliente;
    file.close();
}

void *leerCliente(ifstream &file, int dni){
    int telefono, *ptrDni;
    double *lineaCredito;
    char *nombre, c;
    void **cliente;
    cliente = new void*[4]{};
    ptrDni = new int;
    *ptrDni = dni;
    lineaCredito = new double;
    file >> c;
    nombre = leerCadena(file, 200, ',');
    file >> telefono >> c >> *lineaCredito;
    file.ignore();
    cliente[0] = ptrDni;
    cliente[1] = nombre;
    cliente[2] = nullptr;
    cliente[3] = lineaCredito;
    return cliente;
}

void cargapedidos(void *productos, void *&clientes){
    ifstream file("pedidos2.csv");
    if(not file.is_open()){
        cout << "ERROR: No se pudo abrir el archivo pedidos2.csv" << endl;
        exit(1);
    }
    int dni, cantidadPedida, pos, contador[200]{};
    char *codigo, c;
    void **buffClientes = (void**)clientes;  
    while(true){
        codigo = leerCadena(file, 10, ',');
        if(file.eof()) break;
        file >> dni >> c >> cantidadPedida;
        pos = buscarCliente(clientes, dni);
        if(pos != -1) cargarPedido(buffClientes[pos], contador[pos], codigo, 
                cantidadPedida, productos);
        file.ignore();
    }
    for(int i = 0; buffClientes[i]; i++)
        pasarMemoriaExacta(buffClientes[i], contador[i]);
    file.close();
}

int buscarCliente(void *clientes, int dni){
    int *ptrDni;
    void **cliente = (void**)clientes;
    void **aux;
    for(int i = 0; cliente[i]; i++){
        aux = (void**)cliente[i];
        ptrDni = (int*)aux[0];
        if(*ptrDni == dni) return i;
    }
    return -1;
}

void cargarPedido(void *&cliente, int &contador, char *codigo, int cantidadPedida, 
        void *productos){
    int pos;
    void **producto = (void**)productos;
    pos = buscarProducto(productos, codigo);
    if(pos != -1) cargarProducto(cliente, contador, cantidadPedida, producto[pos], 
            codigo);
}

int buscarProducto(void *productos, char *codigo){
    char *codigoProducto;
    void **producto = (void**)productos;
    void **aux;
    for(int i = 0; producto[i]; i++){
        aux = (void**)producto[i];
        codigoProducto = (char*)aux[0];
        if(strcmp(codigo, codigoProducto) == 0) return i;
    }
    return -1;
}

void cargarProducto(void *&cliente, int &contador, int cantidadPedida, void *producto, 
        char *codigo){
    void **datosProducto = (void**)producto;
    void **datosCliente = (void**)cliente;
    double lineaCliente, lineaNecesitada, precio;
    char tipo;
    lineaCliente = *(double*)datosCliente[3];
    precio = *(double*)datosProducto[2];
    tipo = *(char*)datosProducto[3];
    lineaNecesitada = precio*cantidadPedida;
    if(tipo == 'N' or lineaCliente >= lineaNecesitada){
        lineaCliente -= lineaNecesitada;
        if(tipo == 'S') *(double*)datosCliente[3] = lineaCliente;
        if(datosCliente[2] == nullptr) datosCliente[2] = new void*[200]{};
        asignarPedido(datosCliente[2], contador, codigo, cantidadPedida , 
                lineaNecesitada);
        contador++;
    }
}

void asignarPedido(void *&datosPedido, int contador, char *codigo, int cantidad, 
        double lineaNecesitada){
    void **pedidos = (void**)datosPedido;
    pedidos[contador] = colocarPedido(codigo, cantidad, lineaNecesitada);
}

void *colocarPedido(char *codigo, int cantidad, double lineaNecesitada){
    int *ptrCantidad;
    double *ptrLinea;
    char *ptrCodigo;
    void **pedido;
    pedido = new void*[3]{};
    ptrCantidad = new int;
    ptrLinea = new double;
    ptrCodigo = new char[strlen(codigo)+1];
    *ptrCantidad = cantidad;
    *ptrLinea = lineaNecesitada;
    strcpy(ptrCodigo, codigo);
    pedido[0] = ptrCodigo;
    pedido[1] = ptrCantidad;
    pedido[2] = ptrLinea;
    return pedido;
}

void pasarMemoriaExacta(void *&cliente, int contador){
    void **datosCliente = (void**)cliente;
    datosCliente[2] = pedidosExactos(datosCliente[2], contador);
}

void *pedidosExactos(void *&datosCliente, int contador){
    void **pedido;
    void **datosPedido = (void**)datosCliente;
    pedido = new void*[contador+1]{};
    for(int i = 0; i < contador; i++)
        pedido[i] = datosPedido[i];
    delete[] datosPedido;
    pedido[contador] = nullptr;
    return pedido;
}

void imprimereporte(void *clientes){
    ofstream file("ReporteDePedidos.txt");
    if(not file.is_open()){
        cout << "ERROR: No se pudo abrir el archivo ReporteDePedidos.txt" << endl;
        exit(1);
    }
    void **cliente = (void**)clientes;
    for(int i = 0; cliente[i]; i++){
        imprimirLinea(file, 100, '=');
        imprimirCabecera(file, cliente[i]);
        imprimirPedidos(file, cliente[i]);
    }
}

void imprimirLinea(ofstream &file, int n, char c){
    for(int i = 0; i < n; i++)
        file.put(c);
    file << endl;
}

void imprimirCabecera(ofstream &file, void *datosCliente){
    void **aux = (void**)datosCliente;
    file << left << setw(20) << "DNI";
    file << left << setw(50) << "Nombre";
    file << left << setw(30) << "Credito" << endl;
    file << left << setw(20) << *(int*)aux[0];
    file << left << setw(50) << (char*)aux[1];
    file << left << setw(30) << *(double*)aux[3] << endl;
    imprimirLinea(file, 100, '-');
}

void imprimirPedidos(ofstream &file, void *cliente){
    void **datosCliente = (void**)cliente;
    file << "Pedidos atendidos" << endl;
    imprimirLinea(file, 100, '-');
    file << left << setw(8) << "Codigo";
    file << left << setw(10) << "Cantidad";
    file << left << setw(10) << "Total" << endl;
    imprimirLinea(file, 100, '-');
    imprimirPedido(file, datosCliente[2]);
}

void imprimirPedido(ofstream &file, void *datosPedido){
    void **pedidos = (void**)datosPedido;
    for(int i = 0; pedidos[i]; i++)
        imprimirContenidoPedido(file, pedidos[i]);
}

void imprimirContenidoPedido(ofstream &file, void *pedido){
    void **infoPedido = (void**)pedido;
    int cantidad;
    double total;
    char *codigo;
    cantidad = *(int*)infoPedido[1];
    total = *(double*)infoPedido[2];
    codigo = (char*)infoPedido[0];
    file << left << setw(8) << codigo;
    file << left << setw(10) << cantidad;
    file << left << setw(10) << total << endl;
}