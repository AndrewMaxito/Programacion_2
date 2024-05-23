

/* 
 * File:   alumno.cpp
 * Author: andre
 * 
 * Created on 22 de mayo de 2024, 10:21
 */

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "alumno.h"
#include "nota.h"

alumno::alumno() {
    codigo = 0;
    nombre = nullptr;
    numcurso = 0;
    numaprobados = 0;
    numprimera = 0;
    numsegunda = 0;
    numtercera = 0;
}

alumno::~alumno() {
    if (nombre != nullptr) delete[] nombre;
}

void alumno::SetNombre(const char* cad) {
    if (nombre != nullptr) delete[] nombre;
    nombre = new char [strlen(cad) + 1];
    strcpy(nombre, cad);
}

void alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

void alumno::SetNumtercera(int numtercera) {
    this->numtercera = numtercera;
}

int alumno::GetNumtercera() const {
    return numtercera;
}

void alumno::SetNumsegunda(int numsegunda) {
    this->numsegunda = numsegunda;
}

int alumno::GetNumsegunda() const {
    return numsegunda;
}

void alumno::SetNumprimera(int numprimera) {
    this->numprimera = numprimera;
}

int alumno::GetNumprimera() const {
    return numprimera;
}

void alumno::SetNumaprobados(int numaprobados) {
    this->numaprobados = numaprobados;
}

int alumno::GetNumaprobados() const {
    return numaprobados;
}

void alumno::SetNumcurso(int numcurso) {
    this->numcurso = numcurso;
}

int alumno::GetNumcurso() const {
    return numcurso;
}

int alumno::GetCodigo() const {
    return codigo;
}

void alumno::actulizar() {

    for (int i = 0; lnotas[i].GetCiclo() != 0; i++) {
        char codCurso[100];
        if (lnotas[i].GetNota() > 10) {
            numaprobados++;
            int contador = 0;
            for (int j = 0; j <= i; j++) {
                char buffCursoRep[100];
                lnotas[i].GetCodcurso(codCurso);
                lnotas[j].GetCodcurso(buffCursoRep);
                if (strcmp(codCurso, buffCursoRep) == 0) {
                    contador++;
                }
            }
            switch (contador) {
                case 1:
                    numprimera++;
                    break;
                case 2:
                    numsegunda++;
                    break;
                case 3:
                    numtercera++;
                    break;
            }
        }
        numcurso++;
    }
}


//Sobrecarga

void alumno::operator+=(const class nota& nt) {
    int posIng = 0;
    for (int i = 0; lnotas[i].GetCiclo() != 0; i++)
        posIng++;
    lnotas[posIng] = nt; // esto tambien se sobrecargara
}

void alumno::GetNombre(char *cad) const {
    if (nombre == nullptr) cad[0] = 0;
    else strcpy(cad, nombre);
}

