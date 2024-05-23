
/* 
 * File:   nota.cpp
 * Author: andre
 * 
 * Created on 22 de mayo de 2024, 10:19
 */
#include <cstring>

#include "nota.h"

nota::nota() {
    codcurso = nullptr;
    ciclo = 0;
    Nota = 0;
}

nota::~nota() {
    if (codcurso != nullptr) delete[]codcurso;
}

void nota::SetNota(int Nota) {
    this->Nota = Nota;
}

void nota::SetCiclo(int ciclo) {
    this->ciclo = ciclo;
}

void nota::SetCodcurso(const char* cad) {
    if (codcurso != nullptr) delete[] codcurso;
    codcurso = new char [strlen(cad) + 1];
    strcpy(codcurso, cad);
}

int nota::GetNota() const {
    return Nota;
}

int nota::GetCiclo() const {
    return ciclo;
}

void nota::operator=(const class nota& nt) {
    SetCodcurso(nt.codcurso);
    ciclo = nt.ciclo;
    Nota = nt.Nota;
}

void nota::GetCodcurso(char *cad) const {
    if (codcurso == nullptr) cad[0]=0;
    else strcpy(cad,codcurso);
}
