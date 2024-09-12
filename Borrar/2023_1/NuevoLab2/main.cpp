/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 12 de septiembre de 2024, 11:48 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "MetodoDinamicoExacto.h"

/*
 * 
 */

int main(int argc, char** argv) {
    char **alumnos_Nombre, **curso_Nombre, *alumno_modalidad;
    int *alumno_Codigo, *alumno_Porcentaje, *alumno_escala;
    int **curso_Alumnos;
    double *curso_Creditos;

    lecturaAlumnos("alumnos.csv", alumno_Codigo, alumnos_Nombre, alumno_modalidad,
            alumno_Porcentaje, alumno_escala);
    pruebaDeLecturaAlumnos("ReporteAlumnos.txt", alumno_Codigo, alumnos_Nombre,
            alumno_modalidad, alumno_Porcentaje, alumno_escala);

    //pregunta2
    lecturaCursos("alumnos_cursos.csv", alumno_Codigo, alumno_escala, curso_Nombre,
            curso_Creditos, curso_Alumnos);
    pruebaLecturaCursos("ReporteCursos.csv", curso_Nombre, curso_Creditos, curso_Alumnos);

    //Pregunta 3
    reporteDeRecaudacionPorModalidad("ReporteDeRecaudacionModalidad.txt",
            alumno_Codigo, alumno_modalidad, alumno_Porcentaje, alumnos_Nombre,
            curso_Nombre, curso_Creditos, curso_Alumnos);


    return 0;
}

