
/* 
 * File:   Alumno.cpp
 * Author: andre
 * 
 * Created on 11 de junio de 2024, 18:18
 */

#include <cstring>

#include "Alumno.h"

Alumno::Alumno() {
    codigo=0;
    nombre=nullptr;
    escala=0;
    creditos=0.0;
    total=0.0;
}


Alumno::~Alumno() {
    if (nombre != nullptr)delete[] nombre;
    
}

void Alumno::SetTotal(double total) {
    this->total = total;
}

double Alumno::GetTotal() const {
    return total;
}

void Alumno::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Alumno::GetCreditos() const {
    return creditos;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(const char* cad) {
    if (nombre != nullptr) delete [] nombre;
    nombre = new char [strlen(cad)+1];
    strcpy(nombre,cad);
}

void Alumno::GetNombre(char *cad) const {
    if (nombre == nullptr) cad[0]=0;
    else strcpy(cad,nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

