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
    productos = new char**[n+1]{}; //{} inicializa en nullptr
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

void lecturaDePedidos(const char *filename, int *&fechaPedidos, 
        char ***&codigoPedidos, int ***&dniCantPedidos){
    ifstream file = abrirArchivoLectura(filename);
    int dni, cantidad, dd, mm, aaaa, fecha, posicion, bufferFechas[600], n = 0;
    int **bufferCantPedidos[600], numPedidos[600];
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
                    fecha, numPedidos, n, posicion);
        }
        agregarPedido(bufferCodigoPedidos[posicion], bufferCantPedidos[posicion],
                numPedidos[posicion], dni, cantidad, codigo);
    }
    cargarArreglos(fechaPedidos, codigoPedidos, dniCantPedidos, bufferFechas,
            bufferCodigoPedidos, bufferCantPedidos, numPedidos, n);
}

int buscarFecha(int *bufferFechas, int fecha, int &n){
    for(int i = 0; i < n; i++){
        if(bufferFechas[i] == fecha) return i;
    }
    return -1;
}

void agregarFecha(int ***bufferCantPedidos, char ***bufferCodigoPedidos, 
        int *bufferFechas, int fecha, int *numPedido, int &n, int &posicion){
    bufferFechas[n] = fecha;
    bufferCodigoPedidos[n] = new char*[600];
    bufferCantPedidos[n] = new int*[600];
    numPedido[n] = 0;
    posicion = n;
    n++;
}

void agregarPedido(char **bufferCodigoPedidos, int **bufferCantPedidos,
                int &numPedidos, int dni, int cantidad, char *codigo){
    int *aux;
    bufferCantPedidos[numPedidos] = new int[2];
    aux = bufferCantPedidos[numPedidos];
    aux[0] = dni;
    aux[1] = cantidad;
    bufferCodigoPedidos[numPedidos] = codigo;
    numPedidos++;
}

void cargarArreglos(int *&fechaPedidos, char ***&codigoPedidos, 
        int ***&dniCantPedidos, int *bufferFechas, char ***bufferCodigoPedidos, 
        int ***bufferCantPedidos, int *numPedidos, int n){
    fechaPedidos = new int[n+1];
    codigoPedidos = new char**[n];
    dniCantPedidos = new int**[n];
    for (int i = 0; i < n; i++){
        fechaPedidos[i] = bufferFechas[i];
        codigoPedidos[i] = new char*[numPedidos[i]+1];
        dniCantPedidos[i] = new int*[numPedidos[i]];
        cargarInterno(codigoPedidos[i], dniCantPedidos[i],bufferCodigoPedidos[i],
                bufferCantPedidos[i], numPedidos[i]);
        delete bufferCodigoPedidos[i];
        delete bufferCantPedidos[i];
    }
    fechaPedidos[n] = 0;
}

void cargarInterno(char **&codigoPedidos, int **&dniCantPedidos, 
        char **bufferCodigoPedidos, int **bufferCantPedidos, int numPedidos){
    for (int i = 0; i < numPedidos; i++){
        codigoPedidos[i] = bufferCodigoPedidos[i];
        dniCantPedidos[i] = bufferCantPedidos[i];
    }
    codigoPedidos[numPedidos] = nullptr;
}

void pruebaDeLecturaDePedidos(const char *filename, int *fechaPedidos, 
        char ***codigoPedidos, int ***dniCantPedidos){
    ofstream file = abrirArchivoEscritura(filename);
    if(!file){
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    char **auxCodigos;
    int **auxDni, *auxDniCant;
    for(int i=0; fechaPedidos[i] != 0; i++){
        file << fechaPedidos[i] << endl;
        auxCodigos = codigoPedidos[i];
        auxDni = dniCantPedidos[i];
        for(int j=0; auxCodigos[j] != nullptr; j++){
            auxDniCant = auxDni[j];
            file << setw(10) << auxCodigos[j] << setw(15) << auxDniCant[0] << " " 
                 << auxDniCant[1] << endl;
        }
        file << endl;    
    }
}

void reporteDeEnvioDePedidos(const char* filename, char ***productos, int *&stock,
            double *precios, int *fechaPedidos, char ***codigoPedidos, 
        int ***dniCantPedidos){
    ofstream file = abrirArchivoEscritura(filename);
    double totalIngresos = 0, totalPerdidas = 0;
    file << setw(55) << " "<< "REPORTE DE ENTREGA DE PEDIDOS" << endl;
    imprimirLinea('=', 140, file);
    for(int i = 0; fechaPedidos[i] != 0; i++){
        imprimirFecha(fechaPedidos[i], file);
        imprimirProductos(codigoPedidos[i], dniCantPedidos[i], productos, precios, 
                stock, file, totalIngresos, totalPerdidas);
    }
    imprimirResumenFinal(file, totalIngresos, totalPerdidas);
    file.close();
}

void imprimirResumenFinal(ofstream &file, double totalIngresos, double totalPerdidas){
    file << "Resumen de ingresos" << endl;
    file << left << setw(123) << "Total de ingresos en el periodo:" << right 
            << setw(10) << totalIngresos << endl;
    file << left << setw(123) <<"Total perdido por falta de stock:" << 
            right << setw(10) << totalPerdidas << endl;
    imprimirLinea('=', 140, file);
}

void imprimirProductos(char **codigoPedidos, int **dniCantPedidos, char ***productos, 
        double *precios, int *&stock, ofstream &file, double &ingresosFinal,
        double &perdidasFinal){
    int *auxDniCant, posicion;
    double ingresos, totalIngresos = 0, totalPerdidas = 0;
    char **aux;
    for(int i = 0; codigoPedidos[i] != nullptr; i++){
        auxDniCant = dniCantPedidos[i];
        file.fill('0');
        file << right << setw(2) << i+1 << ")";
        file.fill(' ');
        file << setw(10) << auxDniCant[0] << setw(12) << codigoPedidos[i];
        posicion = buscarProducto(productos, codigoPedidos[i]);
        aux = productos[posicion];
        file << left << setw(3) << " " << setw(60) << aux[1];
        file << right << setw(8) << auxDniCant[1];
        file << fixed << setprecision(2);
        file << right << setw(15) << precios[posicion];
        ingresos = auxDniCant[1]*precios[posicion];
        if(stock[posicion] >= auxDniCant[1]){
            totalIngresos += ingresos;
            file << right << setw(22) << ingresos << endl;
            stock[posicion] -= auxDniCant[1];
        }
        else{
            totalPerdidas += ingresos;
            file << right << setw(22) << "NO HAY STOCK" << endl;
        }
    }
    imprimirResumen(file, totalIngresos, totalPerdidas);
    ingresosFinal += totalIngresos;
    perdidasFinal += totalPerdidas;
}

void imprimirResumen(ofstream &file, double totalIngresos, double totalPerdidas){
    imprimirLinea('-', 140, file);
    file << left << setw(123) << "Total ingresado:" << right << setw(10) << 
            totalIngresos << endl;
    file << left << setw(123) <<"Total perdido por falta de stock:" << 
            right << setw(10) << totalPerdidas << endl;
    imprimirLinea('=', 140, file);
}

int buscarProducto(char ***productos, char *codigo){
    char **aux;
    for(int i = 0; productos[i] != nullptr; i++){
        aux = productos[i];
        if(strcmp(aux[0], codigo) == 0) return i;
    }
    return -1;
}

void imprimirFecha(int fecha, ofstream &file){
    int dd, mm, aaaa;
    dd = fecha%100;
    fecha /= 100;
    mm = fecha%100;
    fecha /= 100;
    aaaa = fecha;
    file.fill('0');
    file << right << "FECHA:   " << setw(2) << dd << "/" << setw(2) << mm << "/" 
            << aaaa << endl;
    imprimirLinea('=', 140, file);
    file.fill(' ');
    file << left << setw(5) << "No." << setw(20) << "DNI" << setw(65) << "Producto"
            << setw(15) << "Cantidad" << setw(15) << "Precio" << 
            "Total de ingresos" << endl;
    imprimirLinea('-', 140, file);
}