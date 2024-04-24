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
    int dni, cantidad, pos, contador[200]{};
    char *codigo, c;
    void **buffClientes = (void**)clientes;
    while(true){
        codigo = leerCadenaExacta(file, 10, ',');
        if(file.eof()) break;
        file >> dni >> c >> cantidad;
        pos = buscarCliente(dni, clientes);
        if(pos != -1) cargarPedido(buffClientes[pos], codigo, productos, cantidad, 
                contador[pos]);
        file.ignore();
    }
    for(int i=0;buffClientes[i]!=nullptr;i++){
        pasarAmemExactaPedidos(buffClientes[i],contador[i]);
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

void cargarPedido(void *&buffClientes, char* codigo, void *productos, int cantidad,
        int &contador){
    int pos;
    void **producto=(void **)productos;
    pos = buscarProducto(codigo, productos);
    if(pos>=0){
        atendemosPedidoProd(buffClientes,codigo,cantidad,producto[pos],contador);
    }
}


int buscarProducto(char *codigo,void *productos){
    void **producto=(void **)productos;
    for(int i=0;producto[i]!=nullptr;i++){
        if(seEncontroProducto(producto[i],codigo)) return i;
    }
    return -1;
}

bool seEncontroProducto(void *producto,char *codigo){
    void **lproducto=(void **)producto;
    char *cod;
    cod = (char *)(lproducto[0]);
    if(strcmp(codigo, cod) == 0) return true;
    return false;
}

void atendemosPedidoProd(void *&buffClientes,char *codigo,int cantidad,
        void *producto,int &contador){
    void **lProducto=(void **)producto,**cliente=(void **)buffClientes;
    char tipoDeProd;
    int lineaNecesitada, lineaCliente;
    double precio;
    lineaCliente = *((int *)cliente[3]);
    precio = *((double *)lProducto[2]);
    lineaNecesitada = (int)(precio)*cantidad;
    tipoDeProd = *((char *)lProducto[3]);
    if(tipoDeProd == 'N' or lineaCliente >= lineaNecesitada){
        lineaCliente -= lineaNecesitada;
        if(tipoDeProd == 'S') *((int *)cliente[3]) = lineaCliente;
        if(cliente[2] == nullptr) cliente[2] = new void*[600];
        asignarPedido(codigo,cantidad,lineaNecesitada,cliente[2],contador);
        contador++;
    }   
}

void asignarPedido(char *codigo,int cantidad,int lineaNecesitada,void *cliente,
        int contador){
    void **pedidoCliente=(void **)cliente;
    pedidoCliente[contador] = colocarPedido(codigo,cantidad,lineaNecesitada);
}

void *colocarPedido(char *codigo,int cantidad,int lineaNecesitada){
    int *cant,*linNe;
    char *cod;
    void **res;
    cod=new char[strlen(codigo)+1];
    cant=new int;
    linNe=new int;
    strcpy(cod,codigo);
    *cant= cantidad;
    *linNe= lineaNecesitada;
    res = new void*[3];
    res[0] = cod;
    res[1] = cant;
    res[2] = linNe;
    return res;
}

void pasarAmemExactaPedidos(void *clientes,int contador){
    void **lclientes=(void **)clientes;
    lclientes[2] = pedidosExactos(lclientes[2],contador);
}

void *pedidosExactos(void *lclientes,int contador){
    void **res;
    void **llclientes=(void **)lclientes;
    res=new void*[contador+1];
    for(int i=0;i<contador;i++) res[i]=llclientes[i];
    delete llclientes;
    res[contador] = nullptr;
    return res;
}