#include "Pregunta01Examen01PunterosMultiples.h"

void cargarPedidos(int **&fechaClienteCantidad, char **&codigoDelProducto, 
        const char *filename){
    ifstream file(filename);
    if(not file.is_open()){
        cout << "ERROR: No se pudo abrir el archivo" << filename << endl;
        exit(1);
    }
    fechaClienteCantidad = nullptr;
    codigoDelProducto = nullptr;
    int n = 0, cap = 0, dni, cant, dd, mm, aaaa, fecha;
    char *codigo, c;
    while(true){
        codigo = leerCadena(file, 15, ',');
        if(file.eof()) break;
        file >> dni >> c >> cant >> c >> dd >> c >> mm >> c >> aaaa;
        file.ignore();
        fecha = convertirFecha(dd, mm, aaaa);
        if(n == cap)
            aumentarEspacios(fechaClienteCantidad, codigoDelProducto, n, cap);
        asignarFechaPedido(fechaClienteCantidad[n-1], fecha, dni, cant);
        codigoDelProducto[n-1] = codigo;
        n++;
    }
    ordenarPedidos(fechaClienteCantidad, codigoDelProducto);
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

int convertirFecha(int dd, int mm, int aaaa){
    int fecha;
    fecha = aaaa*10000 + mm*100 + dd;
    return fecha;
}

void aumentarEspacios(int **&fechaClienteCantidad, char **&codigoDelProducto, 
        int &n, int &cap){
    cap += INCREMENTO;
    int **auxFecha;
    char **auxCod;
    if(fechaClienteCantidad == nullptr){
        fechaClienteCantidad = new int*[cap]{};
        codigoDelProducto = new char*[cap]{};
        n = 1;
    }
    else{
        auxFecha = new int*[cap]{};
        auxCod = new char*[cap]{};
        for(int i = 0; i < n; i++){
            auxFecha[i] = fechaClienteCantidad[i];
            auxCod[i] = codigoDelProducto[i];
        }
        delete[] fechaClienteCantidad;
        delete[] codigoDelProducto;
        fechaClienteCantidad = auxFecha;
        codigoDelProducto = auxCod;
    }
}

void asignarFechaPedido(int *&infoCliente, int fecha, int dni, int cant){
    infoCliente = new int[3]{};
    infoCliente[0] = fecha;
    infoCliente[1] = dni;
    infoCliente[2] = cant;
}

void ordenarPedidos(int **fechaClienteCantidad, char **codigoDelProducto){
    int n = 0;
    while(fechaClienteCantidad[n]) n++;
    mergeSort(fechaClienteCantidad, codigoDelProducto, 0, n-1);
}

void mergeSort(int **fechaClienteCantidad, char **codigoDelProducto, int ini, 
        int fin){
    if(ini >= fin) return;
    int med = (ini+fin)/2;
    mergeSort(fechaClienteCantidad, codigoDelProducto, ini, med);
    mergeSort(fechaClienteCantidad, codigoDelProducto, med+1, fin);
    merge(fechaClienteCantidad, codigoDelProducto, ini, med, fin);
}

void merge(int **fechaClienteCantidad, char **codigoDelProducto, int ini, 
        int med, int fin){
    int nIzq = med-ini+1;
    int nDer = fin-med;
    int **arrIzq, **arrDer;
    char **arrCodIzq, **arrCodDer;
    arrIzq = new int*[nIzq]{};
    arrDer = new int*[nDer]{};
    arrCodIzq = new char*[nIzq]{};
    arrCodDer = new char*[nDer]{};
    copiarArreglos(fechaClienteCantidad, codigoDelProducto, ini, med, nIzq, nDer, 
            arrIzq, arrDer, arrCodIzq, arrCodDer);
    fusionarArreglos(fechaClienteCantidad, codigoDelProducto, ini, nIzq, nDer, 
            arrIzq, arrDer, arrCodIzq, arrCodDer);
    liberarMemoria(arrIzq, arrDer, arrCodIzq, arrCodDer);
}

void copiarArreglos(int **fechaClienteCantidad, char **codigoDelProducto, 
        int ini, int med, int nIzq, int nDer, int **arrIzq, int **arrDer, 
        char **arrCodIzq, char **arrCodDer){
    for(int i = 0; i < nIzq; i++){
        arrIzq[i] = fechaClienteCantidad[ini+i];
        arrCodIzq[i] = codigoDelProducto[ini+i];
    }
    for(int j = 0; j < nDer; j++){
        arrDer[j] = fechaClienteCantidad[med+1+j];
        arrCodDer[j] = codigoDelProducto[med+1+j];
    }
}

void fusionarArreglos(int **fechaClienteCantidad, char **codigoDelProducto, 
        int ini, int nIzq, int nDer, int **arrIzq, int **arrDer, char **arrCodIzq, 
        char **arrCodDer){
    int i = 0, j = 0, k = ini;
    fusionarMientrasAmbos(fechaClienteCantidad, codigoDelProducto, i, j, k, nIzq, 
            nDer, arrIzq, arrDer, arrCodIzq, arrCodDer);
    fusionarRestanteIzq(fechaClienteCantidad, codigoDelProducto, i, k, nIzq, 
            arrIzq, arrCodIzq);
    fusionarRestanteDer(fechaClienteCantidad, codigoDelProducto, j, k, nDer, 
            arrDer, arrCodDer); 
}

void fusionarMientrasAmbos(int **fechaClienteCantidad, char **codigoDelProducto, 
        int &i, int &j, int &k, int nIzq, int nDer, int **arrIzq, int **arrDer,
        char **arrCodIzq, char **arrCodDer) {
    int *auxIzq, *auxDer;
    while(i < nIzq and j < nDer){
        auxIzq = arrIzq[i];
        auxDer = arrDer[j];
        if(auxIzq[0] <= auxDer[0]){
            fechaClienteCantidad[k] = arrIzq[i];
            codigoDelProducto[k] = arrCodIzq[i];
            i++;
        }
        else{
            fechaClienteCantidad[k] = arrDer[j];
            codigoDelProducto[k] = arrCodDer[j];
            j++;
        }
        k++;
    }
}

void fusionarRestanteIzq(int **fechaClienteCantidad, char **codigoDelProducto, 
        int &i, int &k, int nIzq, int **arrIzq, char **arrCodIzq){
    while(i < nIzq){
        fechaClienteCantidad[k] = arrIzq[i];
        codigoDelProducto[k] = arrCodIzq[i];
        i++;
        k++;
    }
}

void fusionarRestanteDer(int **fechaClienteCantidad, char **codigoDelProducto, 
        int &j, int &k, int nDer, int **arrDer, char **arrCodDer){
    while(j < nDer){
        fechaClienteCantidad[k] = arrDer[j];
        codigoDelProducto[k] = arrCodDer[j];
        j++;
        k++;
    }
}

void liberarMemoria(int **arrIzq, int **arrDer, char **arrCodIzq, char **arrCodDer){
    delete[] arrIzq;
    delete[] arrDer;
    delete[] arrCodIzq;
    delete[] arrCodDer;
}

void pruebaDeCargaDePedidos(int **fechaClienteCantidad, char **codigoDelProducto, 
        const char *filename){
    ofstream file(filename);
    if(not file.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    int *aux;
    imprimirCabeceraCargaPedidos(file);
    for(int i = 0; fechaClienteCantidad[i]; i++){
        aux = fechaClienteCantidad[i];
        file << right << aux[0];
        file << right << setw(13) << aux[1];
        file << right << setw(13) << aux[2];
        file << setw(17) << " ";
        file << left << setw(13) << codigoDelProducto[i] << endl;
    }
    file.close();
}

void imprimirCabeceraCargaPedidos(ofstream &file){
    file << left << setw(15) << "FECHA";
    file << left << setw(15) << "DNI";
    file << left << setw(15) << "CANTIDAD";
    file << left << setw(15) << "CODIGO DE PRODUCTO" << endl;
    imprimirLinea(file, 70, '=');
}

void imprimirLinea(ofstream &file, int n, char c){
    for(int i = 0; i < n; i++)
        file.put(c);
    file.put('\n');
}