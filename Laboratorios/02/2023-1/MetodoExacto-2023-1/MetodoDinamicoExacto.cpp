#include "MetodoDinamicoExacto.h"

void lecturaAlumnos(const char *filename, int *&alumno_Codigo, 
        char **&alumno_Nombre, char *&alumno_Modalidad, int *&alumno_Porcentaje, 
        int *&alumno_Escala){
    ifstream file = abrirArchivoLectura(filename);
    int i = 0, bufferCodigo[100], bufferPorcentaje[i], bufferEscala[i];
    char c, *bufferNombre[100], bufferModalidad[100];
    while(true){
        file >> bufferCodigo[i]; 
        if(file.eof()) break;
        file >> c;
        bufferNombre[i] = leerCadenaExacta(file, 100, ',');
        // leerAlumno(file, bufferModalidad, bufferPorcentaje, bufferEscala);
        break;
        i++;
    }
    alumno_Codigo = new int[i+1];
    alumno_Nombre = new char*[i];
    alumno_Escala = new int[i];
    alumno_Modalidad = new char[i];        
    alumno_Porcentaje = new int[i];
    for(int j = 0; j <=i; j++){
        alumno_Codigo[j] = bufferCodigo[j];
        alumno_Nombre[j] = bufferNombre[j];
        alumno_Escala[j] = bufferEscala[j];
        alumno_Modalidad[j] = bufferModalidad[j];
        alumno_Porcentaje[j] = bufferPorcentaje[j];
    }
    alumno_Codigo[i+1] = 0;
}

void leerAlumno(ifstream &file, char *&alumno_Modalidad, int *&alumno_Porcentaje, 
        int *&alumno_Escala){
    char c;
    file >> c;
    
}

char* leerCadenaExacta(ifstream &file, int n, char delim){
    char buffer[n], *cadena;
    file.getline(buffer, n, delim);
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

ifstream abrirArchivoLectura(const char *filename){
    ifstream file(filename);
    if(!file.is_open()){
        cout << "ERROR: NO SE PUDO ABRIR EL ARCHIVO " << filename << endl;
        exit(1);
    }
    return file;
}

void pruebaLecturaAlumnos(const char *filename, int *alumno_Codigo, 
        char **alumno_Nombre, char *alumno_Modalidad, int *alumno_Porcentaje, 
        int *alumno_Escala){
    for(int i = 0; alumno_Codigo[i] != 0; i++){
        cout << alumno_Codigo[i] << " ";
        cout << alumno_Nombre[i] << endl;
    }
}

