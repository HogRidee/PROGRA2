#include "FuncionesExtras.h"

char *leerCadena(ifstream &file, int n, int c){
    char buffer[n], *cadena;
    file.getline(buffer, n, c);
    if(file.eof()) return nullptr;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
}