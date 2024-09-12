

/* 
 * File:   MetodoDinamicoExacto.cpp
 * Author: andre
 * 
 * Created on 12 de septiembre de 2024, 11:53 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#define NO_ENCONTRADO -1
#include "MetodoDinamicoExacto.h"

void lecturaAlumnos(const char *nomArch, int *&alumno_Codigo, char **&alumnos_Nombre,
        char *&alumno_modalidad, int *&alumno_Porcentaje, int *&alumno_escala) {
    ifstream arch(nomArch, ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    //5802,MINAYA AMEZQUITA RHONY JAIME,5
    //2050,LOYOLA HIJAR NICOLAS OSCAR,V,4

    int buffalumnoCodigo[300], buffAlumnoPorc[300], buffAlumnoEsca[300];
    char *buffAlumnoNombre[300], buffAlumnoModalidad[300];
    int cantAlumnos = 0;
    int codigo, escala;
    char c, modalidad;
    while (true) {
        arch >> codigo;
        if (arch.eof())break;
        arch.get(); //coma
        buffalumnoCodigo[cantAlumnos] = codigo;
        buffAlumnoNombre[cantAlumnos] = leerCadenaExacta(arch, ',');
        arch >> escala;
        if (arch.fail()) {
            arch.clear();
            //si entro es por que leyo una letra
            arch >> buffAlumnoModalidad[cantAlumnos] >> c;
            switch (buffAlumnoModalidad[cantAlumnos]) {
                case 'V':
                    buffAlumnoPorc[cantAlumnos] = 0;
                    break;
                case 'S':
                    arch >> buffAlumnoPorc[cantAlumnos] >> c;
                    break;
            }
            arch >> buffAlumnoEsca[cantAlumnos];
        } else {
            buffAlumnoModalidad[cantAlumnos] = 'P';
            buffAlumnoPorc[cantAlumnos] = 0;
            buffAlumnoEsca[cantAlumnos] = escala;
        }
        cantAlumnos++;

    }

    buffalumnoCodigo[cantAlumnos] = 0; //los otros inicializadores no importan por que dependederan de este 
    cantAlumnos++;
    alumno_Codigo = new int [cantAlumnos];
    alumno_modalidad = new char [cantAlumnos];
    alumno_Porcentaje = new int [cantAlumnos];
    alumno_escala = new int [cantAlumnos];
    alumnos_Nombre = new char *[cantAlumnos];

    for (int i = 0; buffalumnoCodigo[i]; i++) {
        alumno_Codigo[i] = buffalumnoCodigo[i];
        alumno_modalidad[i] = buffAlumnoModalidad[i];
        alumno_Porcentaje[i] = buffAlumnoPorc[i];
        alumno_escala[i] = buffAlumnoEsca[i];
        alumnos_Nombre[i] = buffAlumnoNombre[i];
    }

    alumno_Codigo[cantAlumnos - 1] = 0;
    alumno_modalidad[cantAlumnos - 1] = 0;
    alumno_Porcentaje[cantAlumnos - 1] = 0;
    alumno_escala[cantAlumnos - 1] = 0;
    alumnos_Nombre[cantAlumnos - 1] = nullptr;
}

char *leerCadenaExacta(ifstream &arch, char deli) {
    char buff[100], *ptr;
    arch.getline(buff, 100, deli);
    if (arch.eof())return nullptr;
    ptr = new char [strlen(buff) + 1];
    strcpy(ptr, buff);
    return ptr;
}

void pruebaDeLecturaAlumnos(const char *nomArch, int *alumno_Codigo, char **alumnos_Nombre,
        char *alumno_modalidad, int *alumno_Porcentaje, int *alumno_escala) {

    ofstream arch(nomArch, ios::out);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    for (int i = 0; alumno_Codigo[i] != 0; i++) {
        arch << left << setw(10) << alumno_Codigo[i] << setw(50) <<
                alumnos_Nombre[i] << setw(10) << alumno_modalidad[i];
        if (alumno_modalidad[i] == 'S') arch << setw(10) << alumno_Porcentaje[i];
        else arch << setw(10) << ' ';
        arch << alumno_escala[i] << endl;
    }
}

void lecturaCursos(const char *nomArch, int *alumno_Codigo, int *alumno_escala, char **&curso_Nombre,
        double *&curso_Creditos, int **&curso_Alumnos) {
    ifstream arch(nomArch, ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    //8072,Aplicaciones de las Ciencias de la Computacion,3.5
    //6995,Lenguaje de Programacion 1,5
    //4628,Lenguaje de Programacion 2,5

    char *buffCurNom[300]{}; //para hacer la busqueda mas facil
    int *buffCurAlu[300];
    double buffCurCred[300];
    int codigoalu, cantCursos = 0;
    char nombreCurso[100];
    double creditoCur;
    int arrCantAlumnosCurso[200]{};

    while (true) {
        arch >> codigoalu;
        if (arch.eof())break;
        arch.get(); //primera coma
        arch.getline(nombreCurso, 100, ',');
        arch >> creditoCur;
        int posCuso = buscarCurso(buffCurNom, nombreCurso);
        int posAlu = buscarAlumno(alumno_Codigo, codigoalu);
        if (posCuso == NO_ENCONTRADO) {

            posCuso = cantCursos;
            buffCurNom[posCuso] = new char [strlen(nombreCurso) + 1];
            buffCurAlu[posCuso] = new int [400] {
            }; //no creo que haya mas de 200 alumnos dentro de un curso
            strcpy(buffCurNom[posCuso], nombreCurso);
            buffCurCred[posCuso] = creditoCur;
            cantCursos++;
        }
        int escalaAlu = alumno_escala[posAlu];
        agregarDatosAluCurso(buffCurAlu[posCuso], codigoalu, escalaAlu, arrCantAlumnosCurso[posCuso]);
    }

    buffCurNom[cantCursos] = nullptr; //este es el principal
    cantCursos++;
    curso_Nombre = new char *[cantCursos];
    curso_Creditos = new double [cantCursos] {
    };
    curso_Alumnos = new int *[cantCursos] {
    };


    for (int i = 0; buffCurNom[i]; i++) {
        curso_Nombre[i] = buffCurNom[i];
        curso_Creditos[i] = buffCurCred[i];

        curso_Alumnos[i] = new int [arrCantAlumnosCurso[i]*2 + 1] {
        }; //el ultimo dato estara con 0
        int *auxInt = curso_Alumnos[i];
        int *auxIntBuff = buffCurAlu[i];
        for (int j = 0; j < 2 * arrCantAlumnosCurso[i]; j++) {
            auxInt[j] = auxIntBuff[j];
        }
    }
    curso_Nombre[cantCursos - 1] = nullptr; //los otros ya estan terminados en 0
}

int buscarCurso(char **buffCurNom, char *nombreCurso) {
    for (int i = 0; buffCurNom[i]; i++)
        if (strcmp(buffCurNom[i], nombreCurso) == 0) return i;

    return NO_ENCONTRADO;
}

int buscarAlumno(int *alumno_Codigo, int codigoalu) {
    for (int i = 0; alumno_Codigo[i]; i++)
        if (alumno_Codigo[i] == codigoalu) return i;
    cout << "no se encontro al alumno" << endl; //solo por si acaso
    return NO_ENCONTRADO;
}

void agregarDatosAluCurso(int *regAluCur, int codigoalu, int escalaAlu,
        int &CantAlu) {
    regAluCur[2 * CantAlu] = codigoalu;
    regAluCur[2 * CantAlu + 1] = escalaAlu;
    CantAlu++;
}

void pruebaLecturaCursos(const char *nomArch, char **curso_Nombre, double *curso_Creditos,
        int **curso_Alumnos) {
    ofstream arch(nomArch, ios::out);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }

    for (int i = 0; curso_Nombre[i]; i++) {
        arch << left << setw(50) << curso_Nombre[i] << right << setw(10) <<
                curso_Creditos[i] << endl;
        arch << "Alumnos Matriculados" << endl;
        int *auxCurAlu = curso_Alumnos[i];
        for (int j = 0; auxCurAlu[2 * j]; j++) {
            arch << left << setw(10) << auxCurAlu[2 * j] << auxCurAlu[2 * j + 1] << endl;
        }
    }
}

void reporteDeRecaudacionPorModalidad(const char *nomArch, int *alumno_Codigo,
        char *alumno_modalidad, int *alumno_Porcentaje, char **alumnos_Nombre,
        char **curso_Nombre, double *curso_Creditos, int **curso_Alumnos) {
    ofstream arch(nomArch, ios::out);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    arch << fixed << setprecision(2);
    for (int i = 0; curso_Nombre[i]; i++) {
        arch << right << setfill('0') << setw(2) << i + 1 << ")" << setfill(' ') <<
                left << setw(10) << ' ' << setw(20) << "Curso: " << setw(50) <<
                curso_Nombre[i] << setw(15) << "Creditos" << right << setw(7) <<
                curso_Creditos[i] << endl;
        arch << "Alumnos Matriculados" << endl;
        arch << left << setw(4) << ' ' << setw(10) << "Codigo" << setw(47) <<
                "Nombre" << setw(15) << "Escala" << setw(15) << "Modalidad" << "Pagos" << endl;
        int *auxCurAlu = curso_Alumnos[i];
        for (int j = 0; auxCurAlu[2 * j]; j++) {
            int posAlumno = buscarAlumno(alumno_Codigo, auxCurAlu[2 * j]);

            arch << right << setfill('0') << setw(2) << j + 1 << ")" <<
                    setfill(' ') << left << setw(10) << auxCurAlu[2 * j] << setw(50) <<
                    alumnos_Nombre[posAlumno] << setw(15) << auxCurAlu[2 * j + 1] <<
                    setw(15) << alumno_modalidad[posAlumno] << endl;
        }

    }
}