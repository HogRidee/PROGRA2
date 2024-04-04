#include "sobrecargas.h"
#include "Estructuras.h"

bool operator >> (istream &in, StCurso &curso){
    in >> curso.codigoDelCurso;
    if(in.eof()) return false;
    in >> curso.nombreDelCurso >> curso.creditos >> curso.codigoDelProfesor >> 
            curso.nombreDelProfesor;
    curso.ingresos = 0;
    curso.numeroDeAlumnos = 0;
    return true;
}

bool operator >> (istream &in, StAlumno &alumno){
    char c, a;
    in >> alumno.semestre;
    if(in.eof()) return false;
    in >> c >> alumno.codigo >> alumno.nombre;
    in >> c;
    if (c == 'V'){
        strcpy(alumno.modalidad, "VIRTUAL");
        alumno.porcentaje = 0;
        in >> a;
    }
    if (c == 'S'){
        strcpy(alumno.modalidad, "SEMIPRESENCIAL");
        in >> alumno.porcentaje;
        in >> a;
    }
    if (c == 'G'){
        strcpy(alumno.modalidad, "PRESENCIAL");
        alumno.porcentaje = 0;
    }
    in >> alumno.escala;
    alumno.numeroDeCursos = 0;
    alumno.costoTotal = 0.0;
    return true;
}

bool operator >> (istream &in, StRegistroDeMatricula &matricula){
    char c;
    in >> matricula.codigoDelCurso;
    if(in.eof()) return false;
    in >> matricula.semestreDelAlumno >> c >> matricula.codigodelAlumno;
    return true;
}

void operator += (StCurso *arrCurso, const StCurso &curso){
    int i = 0;
    
}