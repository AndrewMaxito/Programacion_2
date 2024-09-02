
/* 
 * File:   Medico.cpp
 * Author: andre
 * 
 * Created on 28 de mayo de 2024, 12:35
 */
#include <cstring>
#include "Medico.h"

Medico::Medico() {
    codigo = 0;
    nombre = nullptr;
    especialidad = nullptr;
}

Medico::~Medico() {
    if (nombre != nullptr) delete[] nombre;
    if (especialidad != nullptr) delete[] especialidad;
}

void Medico::SetEspecialidad(const char* cad) {
    if (especialidad != nullptr)delete[] especialidad;
    especialidad = new char [strlen(cad)+1];
    strcpy(especialidad,cad);
}

void Medico::GetEspecialidad(char *cad) const {
    if (especialidad == nullptr) cad[0]=0;
    else strcpy(cad,especialidad);
}

void Medico::SetNombre(const char* cad) {
    if (nombre != nullptr)delete[] nombre;
    nombre = new char [strlen(cad)+1];
    strcpy(nombre,cad);
}

void Medico::GetNombre(char *cad) const {
    if (nombre == nullptr) cad[0]=0;
    else strcpy(cad,nombre);
}

void Medico::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Medico::GetCodigo() const {
    return codigo;
}

