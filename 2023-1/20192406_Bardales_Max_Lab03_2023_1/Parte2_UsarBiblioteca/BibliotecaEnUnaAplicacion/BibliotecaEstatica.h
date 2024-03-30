
/* 
 * File:   BibliotecaEstatica.h
 * Author: andre
 *
 * Created on 29 de marzo de 2024, 16:25
 */

#ifndef BIBLIOTECAESTATICA_H
#define BIBLIOTECAESTATICA_H

#include <fstream>


bool operator >>(ifstream &arch,struct StCurso &curso);
bool operator >>(ifstream &arch,struct StAlumno &alumno);
bool operator >>(ifstream &arch,struct StRegistroDeMatricula &matricula);

void operator +=(struct StCurso *arrCursos,struct StCurso &cursoIng);
void operator +=(struct StAlumno *arrAlumno,struct StAlumno &aluIng);
void operator *=(struct StCurso *arrCursos,struct StRegistroDeMatricula &matricula);
void operator *=(struct StAlumno *arrAlumno,struct StRegistroDeMatricula &matricula);

void operator <<(ofstream &arch,struct StCurso &curso);
void operator <<(ofstream &arch,struct StAlumno &alumno);

#endif /* BIBLIOTECAESTATICA_H */

