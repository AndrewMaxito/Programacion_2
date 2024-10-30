
/* 
 * File:   Libro.cpp
 * Author: andre
 * 
 * Created on 30 de octubre de 2024, 11:21
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Libro.h"

Libro::Libro() {
    codigo = nullptr;
    nombre = nullptr;
    ancho = 0;
    alto = 0;
    colocado = false;
}

Libro::~Libro() {
    if (codigo != nullptr) delete[] codigo;
    if (nombre != nullptr) delete[] nombre;
}

void Libro::SetColocado(bool colocado) {
    this->colocado = colocado;
}

bool Libro::IsColocado() const {
    return colocado;
}

void Libro::SetAlto(int alto) {
    this->alto = alto;
}

int Libro::GetAlto() const {
    return alto;
}

void Libro::SetAncho(int ancho) {
    this->ancho = ancho;
}

int Libro::GetAncho() const {
    return ancho;
}

void Libro::SetNombre(const char* cad) {
    if (nombre != nullptr)delete[] nombre;
    nombre = new char [strlen(cad) + 1];
    strcpy(nombre, cad);
}

void Libro::GetNombre(char *cad) const {
    if (nombre == nullptr) cad[0] = 0;
    else strcpy(cad, nombre);
}

void Libro::SetCodigo(const char* cad) {
    if (codigo != nullptr)delete[] codigo;
    codigo = new char [strlen(cad) + 1];
    strcpy(codigo, cad);
}

void Libro::GetCodigo(char *cad) const {
    if (codigo == nullptr) cad[0] = 0;
    else strcpy(cad, codigo);
}

void operator>>(ifstream &arch, class Libro &lib) {
    //ABC123, El libro de la Selva, 1, 3
    char codigo[10], nombre[100], c;
    int ancho, alto;

    arch.getline(codigo, 10, ',');
    if (arch.eof())return;
    arch.getline(nombre, 100, ',');
    arch >> ancho >> c >> alto;
    arch.get(); // salto de linea

    //
    lib.SetCodigo(codigo);
    lib.SetNombre(nombre);
    lib.SetAncho(ancho);
    lib.SetAlto(alto);
}

void operator<<(ofstream &arch, class Libro &lib) {
    char codigo[10], nombre[100];
    lib.GetCodigo(codigo);
    lib.GetNombre(nombre);

    arch << left << setw(15) << codigo << setw(60) << nombre << setw(10) << 
            lib.GetAncho() << lib.GetAlto() << endl;
}
