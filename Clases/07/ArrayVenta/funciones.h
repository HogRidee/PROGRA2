#ifndef FUNCIONES_H
#define FUNCIONES_H
#include<fstream>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<iomanip>
using namespace std;

char* leerCadena(ifstream &file, char delim){
    char buffer[200];
    file.getline(buffer, 200, delim);
    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

char** leerCodigoNombre(ifstream &file)
{
    char** cod_nombre = new char*[2];
    cod_nombre[0] = leerCadena(file, ',');
    cod_nombre[1] = leerCadena(file, ',');
    return cod_nombre;
}

void lecturaDeProductos(const char* filename, char*** &productos,
                        int* &stock, double* &precios)
{
    ifstream file(filename);
    if(!file.is_open()) {
        cout<<"El arhcivo "<<filename<<" no se pudo abrir\n";
        exit(1);
    }
    char **buf_productos[200];
    int buf_stock[200];
    double buf_precios[200];
    int n = 0;
    while(true){
        buf_productos[n] = leerCodigoNombre(file);
        if(file.eof()) break;        
        buf_precios[n] = atof(leerCadena(file, ','));
        buf_stock[n] = atoi(leerCadena(file, '\n'));
        n++;
    }
    productos = new char**[n+1]{};
    stock = new int[n+1]{};
    precios = new double[n+1]{};
    for(int i=0;i<n;i++)
    {
        productos[i] = buf_productos[i];
        precios[i] = buf_precios[i];
        stock[i] = buf_stock[i];
    }
    file.close();
}

void pruebaDeLecturaDeproductos(const char* filename, char*** productos,
                        int* stock, double* precios)
{
    ofstream file(filename);
    char** cod_nombre;
    file<<left<<setw(8)<<"Codigo"<<setw(60)<<"Nombre"<<setw(10)<<"Precio"<<setw(10)<<"Stock"<<endl;
    for(int i=0;productos[i];i++){
        cod_nombre = productos[i];
        file<<left<<setw(8)<<cod_nombre[0]<<setw(60)<<cod_nombre[1]<<setw(10)<<precios[i]<<setw(10)<<stock[i]<<endl;
    }
    file.close();
}

int convertirFechaNumero(char *cadena)
{
    char* day = strtok(cadena, "/");
    char* month = strtok(nullptr, "/");
    char* year = strtok(nullptr, "/");
    int fecha = atoi(year)*10000 + atoi(month)*100 + atoi(day);
    return fecha;
}

char** leerLinea(ifstream &file)
{
    char** buf_linea = new char*[4];
    buf_linea[0] = leerCadena(file, ',');
    buf_linea[1] = leerCadena(file, ',');
    buf_linea[2] = leerCadena(file, ',');
    buf_linea[3] = leerCadena(file, '\n');
    return buf_linea;    
}

int buscarFecha(int* buf_fechas, int n, int fecha)
{
    int pos = -1;
    for(int i=0;i<n;i++){
        if(buf_fechas[i] == fecha)
        {
            pos = i; break;
        }
    }
    return pos;
}

void asociarPedidoFecha(char** &linea, char** &buf_codigoPedidos, 
                    int** &buf_dniCantPedidos, int &n_fecha)
{
    if(n_fecha == 0)
    {
        buf_codigoPedidos = new char*[50]{};
        buf_dniCantPedidos = new int*[50]{};
    }    
    buf_codigoPedidos[n_fecha] = linea[0];
    int* dni_cant = new int[2];
    dni_cant[0] = atoi(linea[1]);
    dni_cant[1] = atoi(linea[2]);
    buf_dniCantPedidos[n_fecha] = dni_cant;
    n_fecha++;
}

void lecturaDePedidos(const char* filename,int* &fechaPedidos,
             char*** &codigoPedidos,int*** & dniCantPedidos)
{
    ifstream file(filename);
    if(!file.is_open()) {
        cout<<"El arhcivo "<<filename<<" no se pudo abrir\n";
        exit(1);
    }
    int n = 0, pos = -1;
    int buf_fechas[50];
    char** buf_codigoPedidos[50];
    int** buf_dniCantPedidos[50];
    int n_fecha[50];
    for(int i=0;i<50;i++) n_fecha[i] = 0;    
    while(true){
        char** linea = leerLinea(file);
        if(file.eof()) break;    
        int fecha = convertirFechaNumero(linea[3]);
        int pos = buscarFecha(buf_fechas, n, fecha);        
        if(pos == -1)
            pos = n++;
        buf_fechas[pos] = fecha;        
        asociarPedidoFecha(linea, buf_codigoPedidos[pos], 
                buf_dniCantPedidos[pos], n_fecha[pos]);
    }
    fechaPedidos = new int[n+1]{};
    codigoPedidos = new char**[n+1]{};
    dniCantPedidos = new int**[n+1]{};
    for(int i=0;i<n;i++){
        fechaPedidos[i] = buf_fechas[i];
        //reservar espacio para n_fecha[i];
        codigoPedidos[i] = new char*[n_fecha[i] + 1]{};
        dniCantPedidos[i] = new int*[n_fecha[i] + 1]{};
        for(int j=0;j<n_fecha[i];j++){
            codigoPedidos[i][j] = buf_codigoPedidos[i][j];
            dniCantPedidos[i][j] = buf_dniCantPedidos[i][j];
        }
        //liberar buffers 
        delete[] buf_codigoPedidos[i];
        delete[] buf_dniCantPedidos[i];
    }
    file.close();
}   
     
void pruebaDelecturaDepedidos(const char* filename,int* &fechaPedidos,
             char*** &codigoPedidos,int*** & dniCantPedidos)
{
    ofstream file(filename);
    file<<left<<setw(12)<<"Fecha"<<setw(10)<<"Codigo"<<setw(10)
            <<"DNI"<<setw(10)<<"Cantidad"<<endl;
    for(int i=0;fechaPedidos[i];i++){            
        for(int j=0;codigoPedidos[i][j];j++){ 
            file<<left<<setw(12)<<fechaPedidos[i];
            file<<setw(10)<<codigoPedidos[i][j]
                <<setw(10)<<dniCantPedidos[i][j][0]
                <<setw(10)<<dniCantPedidos[i][j][1]<<endl;
        }
        file<<"========================================\n";
    }
    file.close();
}   
#endif /* FUNCIONES_H */

