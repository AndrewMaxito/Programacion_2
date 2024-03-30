

/* 
 * File:   funcionesAuxiliares.h
 * Author: andre
 *
 * Created on 29 de marzo de 2024, 22:44
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>


void leerCursos(ifstream &archCurso,struct StCurso *arrCur);
void leerAlumnos(ifstream &archAlum,struct StAlumno *arrAlu);
void cargarMatricula(struct StCurso *arrCur,struct StAlumno *arrAlu,
        const char *nomArchivo );

#endif /* FUNCIONESAUXILIARES_H */

