
/* 
 * File:   Sinreceta.cpp
 * Author: andre
 * 
 * Created on 28 de mayo de 2024, 12:41
 */

#include <cstring>

#include "Sinreceta.h"

Sinreceta::Sinreceta() {
    dni=0;
    nombre=nullptr;
}


Sinreceta::~Sinreceta() {
    if (nombre != nullptr)delete[]nombre;
}

void Sinreceta::SetNombreS(const char* cad) {
    if (nombre != nullptr)delete[]nombre;
    nombre= new char [strlen(cad)+1];
    strcpy(nombre,cad);
}

void Sinreceta::GetNombreS(char *cad) const {
    if (nombre == nullptr) cad[0]=0;
    else strcpy(cad,nombre);
}

void Sinreceta::SetDni(int dni) {
    this->dni = dni;
}

int Sinreceta::GetDni() const {
    return dni;
}

