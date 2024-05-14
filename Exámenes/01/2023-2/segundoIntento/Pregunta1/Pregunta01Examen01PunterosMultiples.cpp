#include "Pregunta01Examen01PunterosMultiples.h"

void cargarPedidos(int **&fechaClienteCantidad, char **&codigoDelProducto, 
        const char *filename){
    ifstream file(filename);
    if(not file.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    int n = 0, cap = 0, dni, cant, dd, mm, aaaa, fecha;
    char *codigo, c;
    fechaClienteCantidad = nullptr;
    codigoDelProducto = nullptr;
    while(true){
        codigo = leerCadena(file, 15, ',');
        if(file.eof()) break;
        file >> dni >> c >> cant >> c >> dd >> c >> mm >> c >> aaaa;
        file.ignore();
        fecha = aaaa*10000 + mm*100 + dd;
        if(n == cap)
            aumentarEspacios(fechaClienteCantidad, codigoDelProducto, n, cap);
        asignarFecha(fechaClienteCantidad[n-1], fecha, dni, cant);
        codigoDelProducto[n-1] = codigo;
        n++;
    }
    ordenar(fechaClienteCantidad, codigoDelProducto);
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

void aumentarEspacios(int **&fechaClienteCantidad, char **&codigoDelProducto, 
        int &n, int &cap){
    int **auxFecha;
    char **auxCod;
    cap += INCREMENTO;
    if(fechaClienteCantidad == nullptr){
        fechaClienteCantidad = new int*[cap]{};
        codigoDelProducto = new char*[cap]{};
        n = 1;
    }
    else{
        auxFecha = new int*[cap]{};
        auxCod = new char*[cap]{};
        for(int i = 0; fechaClienteCantidad[i]; i++){
            auxFecha[i] = fechaClienteCantidad[i];
            auxCod[i] = codigoDelProducto[i];
        }
        delete[] fechaClienteCantidad;
        delete[] codigoDelProducto;
        fechaClienteCantidad = auxFecha;
        codigoDelProducto = auxCod;
    }
}

void asignarFecha(int *&fechaClienteCantidad, int fecha, int dni, int cant){
    fechaClienteCantidad = new int[3]{};
    fechaClienteCantidad[0] = fecha;
    fechaClienteCantidad[1] = dni;
    fechaClienteCantidad[2] = cant;
}

void ordenar(int **fechaClienteCantidad, char **codigoDelProducto){
    int n = 0;
    while(fechaClienteCantidad[n]) n++;
    qSort(fechaClienteCantidad, codigoDelProducto, 0, n-1);
}

void qSort(int **fechaClienteCantidad, char **codigoDelProducto, int ini, int fin){
    if(ini >= fin) return;
    int med = (ini+fin)/2;
    cambiar(fechaClienteCantidad[ini], fechaClienteCantidad[med], 
                    codigoDelProducto[ini], codigoDelProducto[med]);
    int limite = ini;
    for(int i = ini+1; i <= fin; i++){
        int *auxF1 = fechaClienteCantidad[i];
        int *auxF2 = fechaClienteCantidad[ini];
        if(auxF1[0] < auxF2[0]){
            limite++;
            cambiar(fechaClienteCantidad[limite], fechaClienteCantidad[i], 
                    codigoDelProducto[limite], codigoDelProducto[i]);
        }
    }
    cambiar(fechaClienteCantidad[limite], fechaClienteCantidad[ini], 
                    codigoDelProducto[limite], codigoDelProducto[ini]);
    qSort(fechaClienteCantidad, codigoDelProducto, ini, limite-1);
    qSort(fechaClienteCantidad, codigoDelProducto, limite+1, fin);
}

void cambiar(int *fechaClienteCantidad1, int *fechaClienteCantidad2, 
                    char *codigoDelProducto1, char *codigoDelProducto2){
    int *auxF;
    char *auxC;
    auxF = fechaClienteCantidad1;
    fechaClienteCantidad1 = fechaClienteCantidad2;
    fechaClienteCantidad2 = auxF;
    auxC = codigoDelProducto1;
    codigoDelProducto1 = codigoDelProducto2;
    codigoDelProducto2 = auxC;
}


void pruebaDeCargaDePedidos(int **fechaClienteCantidad, char **codigoDelProducto, 
            const char *filename){
    ofstream file(filename);
    if(not file.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    imprimirEncabezado(file);
    int *auxF;
    for(int i = 0; fechaClienteCantidad[i]; i++){
        auxF = fechaClienteCantidad[i];
        file << right << auxF[0];
        file << right << setw(15) << auxF[1];
        file << right << setw(13) << auxF[2];
        file << setw(10) << " ";
        file << left << setw(15) << codigoDelProducto[i] << endl;
    }
    file.close();
}

void imprimirEncabezado(ofstream &file){
    file << left << setw(15) << "FECHA";
    file << left << setw(15) << "DNI";
    file << left << setw(15) << "CANTIDAD";
    file << left << setw(15) << "CODIGO" << endl;
    imprimirLinea(file, 70, '=');
}

void imprimirLinea(ofstream &file, int n, char c){
    for(int i = 0; i < n; i++)
        file.put(c);
    file.put('\n');
}
