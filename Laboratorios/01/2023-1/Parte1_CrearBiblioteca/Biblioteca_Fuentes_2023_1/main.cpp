/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 4 de abril de 2024, 10:43
 */

#include "sobrecargas.h"

int main(int argc, char** argv) {

    ifstream archCursos, archAlumnos, archMatricula;
    
    AperturaDeUnArchivoDeTextosParaLeer(archCursos, "Cursos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archAlumnos, "Alumnos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archMatricula, "Matricula.txt");
    
    StCurso arrCursos[100];
    int nCursos = 0;
    while(archCursos >> arrCursos[nCursos]){
        nCursos++;
    }
    for (int i = 0; i < nCursos; i++){
        cout << arrCursos[i].codigoDelCurso << " ";
        cout << arrCursos[i].nombreDelCurso << " "<< arrCursos[i].creditos<< " " 
                << arrCursos[i].codigoDelProfesor << " " << 
                arrCursos[i].nombreDelProfesor << endl;
    }
    cout << endl;
    StAlumno arrAlumnos[100];
    int nAlumnos = 0;
    while(archAlumnos >> arrAlumnos[nAlumnos]){
        nAlumnos++;
    }
    for (int i = 0; i < nAlumnos; i++){
        cout << arrAlumnos[i].semestre << " ";
        cout << arrAlumnos[i].codigo << " ";
        cout << arrAlumnos[i].nombre << " ";
        cout << arrAlumnos[i].modalidad << " ";
        cout << arrAlumnos[i].porcentaje << " ";
        cout << arrAlumnos[i].escala << " " << endl;
    }
    cout << endl;
    StRegistroDeMatricula arrMatricula[100];
    int nMatriculas = 0;
    
    while(archMatricula >> arrMatricula[nMatriculas]){
        nMatriculas++;
    }
    for (int i = 0; i < nMatriculas; i++){
        cout << arrMatricula[i].codigoDelCurso << " ";
        cout << arrMatricula[i].semestreDelAlumno << " ";
        cout << arrMatricula[i].codigodelAlumno << endl;
    }
    
    archCursos.close();
    archAlumnos.close();
    archMatricula.close();
    
    return 0;
}

