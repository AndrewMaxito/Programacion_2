
/* 
 * File:   MetodoDinamicoExacto.h
 * Author: andre
 *
 * Created on 8 de abril de 2024, 11:29
 */

#ifndef METODODINAMICOEXACTO_H
#define METODODINAMICOEXACTO_H

void lecturaAlumnos(const char *nombArch, int *&alumno_Codigo,
        char** &alumno_Nombre, char *&alumno_Modalidad, int *& alumno_Porcentaje,
        int *&alumno_Escala);
char *leerCadenaExacta(ifstream &archAlum);

void pruebaLecturaAlumnos(const char *nombArch, int *alumno_Codigo,
        char** alumno_Nombre, char *alumno_Modalidad, int * alumno_Porcentaje,
        int *alumno_Escala);


void lecturaCursos(const char *nomArch, int *alumno_Codigo, int *alumno_Escala, 
        char **&curso_Nombre, double *&curso_Credito, int **& curso_Alumnos);

void pruebaLecturaCursos(const char *nomArch,char **curso_Nombre,double *curso_Credito,
            int ** curso_Alumnos);




int buscarCurso(char **buffNomCur,char *codCurso,int cantCurs);
int buscarPosAlumno(const int *alumno_Codigo,int codigoAlum);

#endif /* METODODINAMICOEXACTO_H */

