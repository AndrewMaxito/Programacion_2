/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MetodoDinamicoExacto.h
 * Author: andre
 *
 * Created on 12 de septiembre de 2024, 11:53 AM
 */

#ifndef METODODINAMICOEXACTO_H
#define METODODINAMICOEXACTO_H

void lecturaAlumnos(const char *nomArch,int *&alumno_Codigo,char **&alumnos_Nombre,
        char *&alumno_modalidad,int *&alumno_Porcentaje,int *&alumno_escala);
char *leerCadenaExacta(ifstream &arch,char deli);
void pruebaDeLecturaAlumnos(const char *nomArch,int *alumno_Codigo,char **alumnos_Nombre,
        char *alumno_modalidad,int *alumno_Porcentaje,int *alumno_escala);

void lecturaCursos(const char *nomArch,int *alumno_Codigo,int *alumno_escala,char **&curso_Nombre,
            double *&curso_Creditos,int **&curso_Alumnos);
int buscarCurso(char **buffCurNom,char *nombreCurso);
int buscarAlumno(int *alumno_Codigo,int codigoalu);
void agregarDatosAluCurso(int *regAluCur,int codigoalu,int escalaAlu,
        int &CantAlu);
void pruebaLecturaCursos(const char *nomArch,char **curso_Nombre,double *curso_Creditos,
            int **curso_Alumnos);


void reporteDeRecaudacionPorModalidad(const char *nomArch,int *alumno_Codigo,
             char *alumno_modalidad, int *alumno_Porcentaje, char **alumnos_Nombre,
            char **curso_Nombre,double *curso_Creditos,int **curso_Alumnos);

#endif /* METODODINAMICOEXACTO_H */
