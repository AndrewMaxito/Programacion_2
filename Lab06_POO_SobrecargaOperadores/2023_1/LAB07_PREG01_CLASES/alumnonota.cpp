

/* 
 * File:   alumnonota.cpp
 * Author: andre
 * 
 * Created on 22 de mayo de 2024, 10:17
 */
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "alumnonota.h"
#include "nota.h"

alumnonota::alumnonota() {
    codigo = 0;
    codcurso = nullptr;
    cliclo = 0;
    nota = 0;
}

alumnonota::~alumnonota() {
    if (codcurso != nullptr) delete[]codcurso;
}

void alumnonota::SetNota(int nota) {
    this->nota = nota;
}

void alumnonota::SetCliclo(int cliclo) {
    this->cliclo = cliclo;
}

void alumnonota::SetCodcurso(const char* cad) {
    if (codcurso != nullptr) delete[] codcurso;
    codcurso = new char [strlen(cad) + 1];
    strcpy(codcurso, cad);
}

void alumnonota::SetCodigo(int codigo) {
    this->codigo = codigo;
}

void alumnonota::operator & (class nota &nt) const{
    nt.SetCodcurso(codcurso);
    nt.SetCiclo(cliclo);
    nt.SetNota(nota);
}

int alumnonota::GetNota() const {
    return nota;
}

int alumnonota::GetCliclo() const {
    return cliclo;
}

int alumnonota::GetCodigo() const {
    return codigo;
}


