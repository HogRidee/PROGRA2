/* 
 * File:   main.cpp
 * Author: ivana
 *
 * Created on 5 de abril de 2024, 03:54 PM
 */


#include "funciones.h"


int main(int argc, char** argv) {

    char **codigos = nullptr;
    char **nombres = nullptr;
    char ***cursos = nullptr;
    
    leerDatos("Alumnos-Cursos.csv", codigos, nombres, cursos);
    mostrarDatos(codigos, nombres, cursos);
    
    return 0;
}

