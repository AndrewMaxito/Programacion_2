/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 8 de abril de 2024, 11:27
 */

#include <iostream>
#include <iomanip>

using namespace std;

#include "MetodoDinamicoExacto.h"

int main(int argc, char** argv) {
    char **alumno_Nombre, **curso_Nombre, *alumno_Modalidad;
    int *alumno_Codigo, *alumno_Porcentaje, *alumno_Escala;
    int **curso_Alumnos;
    double *curso_Credito;

    lecturaAlumnos("alumnos.csv", alumno_Codigo, alumno_Nombre, alumno_Modalidad,
            alumno_Porcentaje, alumno_Escala);
    pruebaLecturaAlumnos("ReporteAlumno.txt", alumno_Codigo, alumno_Nombre, alumno_Modalidad,
            alumno_Porcentaje, alumno_Escala);

    lecturaCursos("alumnos_cursos.csv", alumno_Codigo, alumno_Escala, curso_Nombre, 
            curso_Credito, curso_Alumnos);
    
    pruebaLecturaCursos("ReporteCursos.txt",curso_Nombre,curso_Credito,curso_Alumnos);




    return 0;
}

