#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Estructuras.h"
#include "AperturaDeArchivos.h"

bool operator>>(ifstream &arch, struct StCurso &curso) {
    // INF263   Algoritmia   3.75   35030611   INGA_FLORES_CESAR_ADOLFO
    char buff[7];
    arch >> buff;
    if (arch.eof()) return false;
    strcpy(curso.codigoDelCurso, buff);
    arch >> curso.nombreDelCurso >> curso.creditos >> curso.codigoDelProfesor >>
            curso.nombreDelProfesor;
    curso.numeroDeAlumnos = 0;
    curso.ingresos = 0;
    return true;
}

bool operator>>(ifstream &arch, struct StAlumno &alumno) {
    int semestreIng;
    char c, mod;
    //20211,1260   GORDILLO/CASTRO/RONAL          G2
    //20211,1397   ZEVALLOS/PRADO/RICARDO   S   50   G2
    arch>>semestreIng;
    if (arch.eof()) return false;
    alumno.semestre = semestreIng;
    arch.get();
    arch >> alumno.codigo >> alumno.nombre >> mod;

    switch (mod) {
        case 'S':
            strcpy(alumno.modalidad, "SEMIPRESENCIAL");
            arch >> alumno.porcentaje >> c >> alumno.escala;
            break;

        case 'V':
            strcpy(alumno.modalidad, "VIRTUAL");
            alumno.porcentaje = 0;
            arch >> c >> alumno.escala;
            break;

        case 'G':
            strcpy(alumno.modalidad, "PRESENCIAL");
            alumno.porcentaje = 0;
            arch >> alumno.escala;
            break;
    }

    alumno.numeroDeCursos = 0;
    alumno.costoTotal = 0;
    return true;
}

bool operator>>(ifstream &arch, struct StRegistroDeMatricula &matricula) {
    char c, buff[7];
    arch >> buff;
    if (arch.eof()) return false;
    strcpy(matricula.codigoDelCurso, buff);
    arch >> matricula.semestreDelAlumno >> c >> matricula.codigodelAlumno;
    return true;
}

void operator+=(struct StCurso *arrCursos, struct StCurso &cursoIng) {
    int i = 0; //pos final
    while (strcmp(arrCursos[i].codigoDelCurso, "XXXXXX") != 0 and arrCursos[i].codigoDelCurso[0] != '\0') i++;
    arrCursos[i] = cursoIng;
    strcpy(arrCursos[i + 1].codigoDelCurso, "XXXXXX");
}

void operator+=(struct StAlumno *arrAlumno, struct StAlumno &aluIng) {
    int i = 0; //pos final
    while (arrAlumno[i].semestre != 0) i++;
    arrAlumno[i] = aluIng;
    arrAlumno[i + 1].semestre = 0;
}

void operator*=(struct StCurso *arrCursos, struct StRegistroDeMatricula &matricula) {
    for (int pos = 0; strcmp(arrCursos[pos].codigoDelCurso, "XXXXXX") != 0 and
            arrCursos[pos].codigoDelCurso[0] != '\0'; pos++) {
        if (strcmp(arrCursos[pos].codigoDelCurso, matricula.codigoDelCurso) == 0) {
            arrCursos[pos].alumnos[arrCursos[pos].numeroDeAlumnos] = 
                    matricula.semestreDelAlumno * 10000 +  matricula.codigodelAlumno;
            arrCursos[pos].numeroDeAlumnos++;
            break;
        }
    }
}

void operator*=(struct StAlumno *arrAlumno, struct StRegistroDeMatricula &matricula) {


    for (int pos = 0; arrAlumno[pos].semestre != 0; pos++) {
        if (arrAlumno[pos].codigo == matricula.codigodelAlumno and arrAlumno[pos].semestre == matricula.semestreDelAlumno ) { //Tambien se deberia tomar en cuenta la cantidad de cursos maximos
            arrAlumno[pos].cursos[arrAlumno[pos].numeroDeCursos] =
                    new char [strlen(matricula.codigoDelCurso) + 1];
            strcpy(arrAlumno[pos].cursos[arrAlumno[pos].numeroDeCursos], matricula.codigoDelCurso);
            arrAlumno[pos].numeroDeCursos++;
            break;
        }
    }
}

void operator<<(ofstream &arch, struct StCurso &curso) {
    arch << left << setw(15) << "Codigo " << setw(25) << "Nombre" << "Creditos" << endl;
    arch << setw(15) << curso.codigoDelCurso << setw(25) << curso.nombreDelCurso <<
            right << curso.creditos << endl;
    arch << left << "Profesor:  " << setw(26) << curso.nombreDelProfesor << '[' <<
            curso.codigoDelProfesor << ']' << endl;
    arch << "Alumnos matriculados: " << endl;
    arch << setw(12) << "Semestre" << "Codigo" << right << endl;
    for (int i = 0; curso.numeroDeAlumnos > i; i++) {
        arch << setw(7) << curso.alumnos[i] / 10000 << setw(10) << curso.alumnos[i] % 10000 << endl;
        ;
    }

    arch << "Numero de de alumnos " << curso.numeroDeAlumnos << endl;
    arch << "Total  Ingresado " << curso.ingresos << endl;
}

void operator<<(ofstream &arch, struct StAlumno &alumno) {
    arch << left << setw(15) << "Semestre " << setw(10) << "Codigo" << setw(30) << "Nombre" <<
            setw(27) << "Modalidad" << "Escala" << endl;
    arch << setw(15) << alumno.semestre << setw(10) << alumno.codigo << setw(30) << alumno.nombre <<
            alumno.modalidad;
    if (strcmp(alumno.modalidad, "SEMIPRESENCIAL") == 0)arch << " Con  " << alumno.porcentaje <<
            setw(7) << "%" << alumno.escala << right << endl;
    else arch << right << setw(20) << alumno.escala << endl;

    arch << "Codigo de cursos matriculados: " << endl;
    for (int i = 0; alumno.numeroDeCursos > i; i++) arch << setw(20) << alumno.cursos[i] << endl;
    arch << "Numero de Cursos: " << alumno.numeroDeCursos << endl;
    arch << "Costo total:  " << alumno.costoTotal << endl;
}


