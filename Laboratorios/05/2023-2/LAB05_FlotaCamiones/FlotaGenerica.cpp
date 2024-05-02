#include "FlotaGenerica.h"

void cargacamiones(void *&flota, int numcamiones, double pesomaximo, 
        void * (*leenumero)(ifstream&),int (*calculanumero)(void*),const char *filename){
    ifstream file(filename);
    if(not file.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << filename << endl;
        exit(1);
    }
    flota = nullptr;
    int contador = 0;
    void *dato;
    while(contador < numcamiones){
        dato = leenumero(file);
        if(file.eof()) break;
        push(dato, flota, calculanumero, pesomaximo, contador);
    }
    file.close();
}

void push(void *dato, void *&flota, int (*calculanumero)(void*), double pesomaximo, 
        int &contador){
    if(flota == nullptr){
        void **nodo = new void*[2];
        nodo[0] = dato;
        nodo[1] = flota;
        flota = nodo;
        contador++;
    }
    else{
        void **nodoActual = (void**)flota;
        cout << "El peso actual del camión es: " << *(int*)nodoActual[0] << " ";
        cout << "El peso que quiero agregar es: " << *(int*)dato << endl;
        if(*(int*)nodoActual[0] + *(int*)dato <= (int)pesomaximo){
            *(int*)nodoActual[0] = *(int*)nodoActual[0] + *(int*)dato;
            cout << "Es posible agregar" << endl;
        }
        else{
            cout << "No es posible agregar" << endl;
            void **nodo = new void*[2];
            nodo[0] = dato;
            nodo[1] = flota;
            flota = nodo;
            contador++;
        }
    }
}

void muestracamiones(void *flota, int numcamiones,void (*imprimenumero)(void*),
        const char *filename){
    int contador = 0;
    void **camiones = (void**)flota;
    while(contador < numcamiones){
        imprimenumero(camiones[0]);
        camiones = (void**)(camiones[1]);
        contador++;
    }
    cout << endl;
}