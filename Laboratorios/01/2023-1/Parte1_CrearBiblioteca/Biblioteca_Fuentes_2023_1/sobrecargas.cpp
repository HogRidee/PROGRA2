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
    int nCursos = 0;
    while(true){
        if(strcmp(arrCurso[nCursos].codigoDelCurso, "XXXXXX") == 0) break;
        nCursos++;
    }
    for(int i = 0; i < curso.numeroDeAlumnos; i++){
        arrCurso[nCursos].alumnos[i] = curso.alumnos[i];
    }
    strcpy(arrCurso[nCursos].codigoDelCurso, curso.codigoDelCurso);
    strcpy(arrCurso[nCursos].nombreDelCurso, curso.nombreDelCurso);
    strcpy(arrCurso[nCursos].nombreDelProfesor, curso.nombreDelProfesor);
    arrCurso[nCursos].codigoDelProfesor = curso.codigoDelProfesor;
    arrCurso[nCursos].creditos = curso.creditos;
    arrCurso[nCursos].ingresos = curso.ingresos;
    arrCurso[nCursos].numeroDeAlumnos = curso.numeroDeAlumnos;
    strcpy(arrCurso[nCursos+1].codigoDelCurso, "XXXXXX");
}

void operator += (StAlumno *arrAlumnos, const StAlumno &alumno){
    int nAlumnos = 0;
    while(true){
        if(arrAlumnos[nAlumnos].semestre == 0) break;
        nAlumnos++;
    }
    arrAlumnos[nAlumnos].codigo = alumno.codigo;
    arrAlumnos[nAlumnos].costoTotal = alumno.costoTotal;
    for (int i = 0; i < alumno.numeroDeCursos; i++){
        strcpy(arrAlumnos[nAlumnos].cursos[i], alumno.cursos[i]);
    }
    arrAlumnos[nAlumnos].escala = alumno.escala;
    strcpy(arrAlumnos[nAlumnos].modalidad, alumno.modalidad);
    strcpy(arrAlumnos[nAlumnos].nombre, alumno.nombre);
    arrAlumnos[nAlumnos].numeroDeCursos = alumno.numeroDeCursos;
    arrAlumnos[nAlumnos].porcentaje = alumno.porcentaje;
    arrAlumnos[nAlumnos].semestre = alumno.semestre;
    arrAlumnos[nAlumnos+1].semestre = 0;
}

void operator *= (StCurso *arrCursos, const StRegistroDeMatricula &matricula){
    int posicion = 0;
    while(true){
        if(strcmp(arrCursos[posicion].codigoDelCurso, matricula.codigoDelCurso)
                == 0) break;
        posicion++;
    }
}