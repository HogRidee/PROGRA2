#include "MetodoIncrementoDeMemoria.h"
#include "AperturaDeArchivos.h"
#define INCREMENTO 5

void lecturaDeLibros(const char*archLib,char ***&libros,int **&stock){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,archLib);
    int n=0,cap = 0;
    char *codigo,*nombre,*autor,c;
    int stockVar;
    double precio;
    libros = nullptr;
    while(true){
        arch>>ws;
        codigo = leerCadenaExacta(arch);
        if(arch.eof())break;
        nombre = leerCadenaExacta(arch);
        autor = leerCadenaExacta(arch);
        arch>>stockVar>>c>>precio;
        if(cap == n)aumentarEspacio(libros,stock,cap,n);
        asignarValores(libros,stock,codigo,nombre,autor,stockVar,n);
        n++;
    }
}
char *leerCadenaExacta(ifstream &arch){
    char *cadena,buffer[200];
    if(arch.eof())return nullptr;
    arch.getline(buffer,200,',');
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena,buffer);
    return cadena;
}
void aumentarEspacio(char ***&libros,int **&stock,int &cap,int &n){
    cap+=INCREMENTO;
    if(libros == nullptr){
        libros = new char**[cap]{};
        stock = new int*[cap]{};
        n = 1;
    }else{
        char ***auxLib = new char**[cap]{};
        int **auxStock = new int*[cap]{};
        for(int i=0;i<n;i++){
            auxLib[i] = libros[i];
            auxStock[i] = stock[i];
        }
        delete libros;
        delete stock;
        libros = auxLib;
        stock = auxStock;
    }
}
void asignarValores(char ***&libros,int **&stock,char *codigo,char *nombre,char *autor,int stockVar,int n){
    libros[n-1] = new char*[3];
    stock[n-1] = new int[2];
    char **auxLib = libros[n-1];
    int *auxStock = stock[n-1];
    auxLib[0] = codigo;
    auxLib[1] = nombre;
    auxLib[2] = autor;
    auxStock[0] = stockVar;
    auxStock[1] = 0;
}
void pruebaDeLecturaDeLibros(const char*archRep,char ***libros,int **stock){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,archRep);
    char **aux;
    int *auxStock;
    for(int i=0;libros[i];i++){
        aux = libros[i];
        auxStock = stock[i];
        arch<<aux[0]<<" "<<left<<setw(60)<<aux[1]<<" "<<setw(35)<<aux[2]<<" "<<right<<setw(10)<<auxStock[0]<<" "<<auxStock[1]<<endl;
    }
}
void atencionDePedidos(const char*archPed,char ***libros,int **&stock,int **&pedidosClientes,char ***&pedidosLibros,bool **&pedidosAtendidos){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,archPed);
    int pedidos,dni,nGeneral=0,capGeneral=0,pos,nPedidos[200]{},capPedidos[200]{},nLibros = 0,capLibros = 0,nArrLibros[200]{},capArrLibros[200]{};
    char c,*codigoLibro;
    bool noLeyo = true;
    pedidosClientes = nullptr;
    pedidosLibros = nullptr;
    while(true){
        arch>>ws;
        arch>>pedidos;
        if(arch.eof())break;
        arch>>c>>dni;
        pos = buscaDni(dni,pedidosClientes,nGeneral);
        
        if(pos == -1){
           if(nGeneral==capGeneral)aumentarEspacioVersion2(pedidosClientes,nGeneral,capGeneral);
           pedidosClientes[nGeneral-1] = nullptr;
           pos = nGeneral-1;
           nGeneral++;
        }
        agregarPedido(pedidosClientes[pos],pedidos,dni,nPedidos[pos],capPedidos[pos]);
        while(arch.get()!='\n'){
            codigoLibro = leerCadenaExactaVersion2(arch);
            if(nLibros == capLibros)aumentarEspacioLibros(pedidosLibros,pedidosAtendidos,nLibros,capLibros);
            agregarLibros(pedidosLibros[nLibros-1],pedidosAtendidos[nLibros-1],codigoLibro,libros,stock,nArrLibros[nLibros-1],capArrLibros[nLibros-1]);
            noLeyo = false;
        }
        nLibros++;
        if(noLeyo) nLibros--;
        noLeyo = true;
    }
    bool *aux;
    for(int i=0;pedidosAtendidos[i];i++){
        aux = pedidosAtendidos[i];
        for(int j=0;aux[j];j++){
            if(aux[j])cout<<"SI ";
            if(not aux[j])cout<<"NO ";
        }
        cout<<endl;
    }
}
int buscaDni(int dni,int **pedidosClientes,int n){
    int *aux;
    
    for(int i=0;i<n-1;i++){
        aux = pedidosClientes[i];
        if(dni == aux[0])return i;
    }
    return -1;
}
char *leerCadenaExactaVersion2(ifstream &arch){
    char *cadena,buffer[50];
    arch>>ws>>buffer;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena,buffer);
    return cadena;
}
void aumentarEspacioVersion2(int **&pedidosClientes,int &n,int &cap){
    cap+=INCREMENTO;
    if(pedidosClientes == nullptr){
        pedidosClientes = new int*[cap]{};
        n = 1;
    }else{
        int **auxPed = new int*[cap]{};
        for(int i=0;i<n;i++){
            auxPed[i] = pedidosClientes[i];
        }
        delete pedidosClientes;
        pedidosClientes = auxPed;
    }
}
void agregarPedido(int *&pedidosClientes,int pedidos,int dni,int &n,int &cap){
    
    if(n==cap) aumentarEspacioInterno(pedidosClientes,dni,n,cap);
    
    pedidosClientes[n-1] = pedidos;
    pedidosClientes[1]++;
    
    n++;
}
void aumentarEspacioInterno(int *&pedidosClientes,int dni,int &n,int &cap){
    cap+=INCREMENTO;
    if(pedidosClientes == nullptr){
        pedidosClientes = new int[cap]{};
        pedidosClientes[0] = dni;
        pedidosClientes[1] = 0;
        n=3;
    }else{
        int *auxPedidoCliente = new int[cap]{};
        for(int i=0;i<n;i++){
            auxPedidoCliente[i] = pedidosClientes[i];
        }
        delete pedidosClientes;
        pedidosClientes = auxPedidoCliente;
    }
}
void aumentarEspacioLibros(char ***&pedidosLibros,bool **&pedidosAtendidos,int &n,int &cap){
    cap +=INCREMENTO;
    if(pedidosLibros == nullptr){
        pedidosLibros = new char**[cap]{};
        pedidosAtendidos = new bool*[cap]{};
        n=1;
    }else{
        char ***auxLibros = new char**[cap]{};
        bool **auxAtendidos = new bool*[cap]{};
        for(int i=0;i<n;i++){
            auxLibros[i] = pedidosLibros[i];
            auxAtendidos[i] = pedidosAtendidos[i];
        }
        delete pedidosLibros;
        delete pedidosAtendidos;
        pedidosLibros = auxLibros;
        pedidosAtendidos = auxAtendidos;
    }
}
void agregarLibros(char **&pedidosLibros,bool*&pedidosAtendidos,char *codigoLibro,char ***libros,int **&stock,int &n,int &cap){
    if(n==0){
        pedidosLibros = nullptr;
        pedidosAtendidos = nullptr;
    }
    if(n==cap){
        aumentarEspacioInternoLibro(pedidosLibros,pedidosAtendidos,n,cap);
    }
    pedidosLibros[n-1] = codigoLibro;
    colocarAtendido(pedidosAtendidos,codigoLibro,libros,stock,n);
    n++;
}
void colocarAtendido(bool *&pedidosAtendidos,char *codigoLibro,char ***libros,int **&stock,int n){
    int pos = buscaCodigo(codigoLibro,libros);
    int *aux = stock[pos];
    if(aux[0]>0){
        pedidosAtendidos[n-1] = true;
        aux[0]--;
    }else{
        pedidosAtendidos[n-1] = false;
        aux[1]++;
    }
}
int buscaCodigo(char *codigoLibro,char ***libros){
    
    for(int i=0;libros[i];i++){
        char **aux = libros[i];
        if(strcmp(aux[0],codigoLibro)==0)return i;
    }
    return -1;
}
void aumentarEspacioInternoLibro(char **&pedidosLibros,bool *&pedidosAtendidos,int &n,int &cap){
    cap+=INCREMENTO;
    if(pedidosLibros == nullptr){
        pedidosLibros = new char*[cap]{};
        pedidosAtendidos = new bool[cap]{};
        n=1;
    }else{
        char **auxPedidos = new char*[cap]{};
        bool *auxPedAten = new bool[cap]{};
        for(int i=0;i<n;i++){
            auxPedidos[i] = pedidosLibros[i];
            auxPedAten[i] = pedidosAtendidos[i];
        }
        delete pedidosLibros;
        delete pedidosAtendidos;
        pedidosLibros = auxPedidos;
        pedidosAtendidos = auxPedAten;
    }
}

