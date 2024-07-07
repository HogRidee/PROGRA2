#include "Util.h"

void imprimirLinea(ofstream &arch, int n, char c){
    for(int i = 0; i < n; i++)
        arch.put(c);
    arch << endl;
}