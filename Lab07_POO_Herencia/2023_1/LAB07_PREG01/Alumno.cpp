

/* 
 * File:   Alumno.cpp
 * Author: andre
 * 
 * Created on 27 de mayo de 2024, 18:27
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#include "Alumno.h"

Alumno::Alumno() {
    codigo = 0;
    nombre = nullptr;
    escala = 0;
    total = 0.0;
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

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(const char* cad) {
    if (nombre != nullptr)delete[]nombre;
    nombre = new char [strlen(cad) + 1];
    strcpy(nombre, cad);
}

void Alumno::GetNombre(char* cad) const {
    if (nombre != nullptr)cad[0] = 0;
    else strcpy(cad, nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::leerDatos(ifstream& arch) {
    char c, nomb[100];
    arch >> codigo;
    if (arch.eof()) return;
    arch.get();
    arch.getline(nomb, 100, ',');
    SetNombre(nomb);
    arch >> escala;
    arch.get();
}

void Alumno::imprime(ofstream&arch) {
    arch << left << setw(10) << codigo << setw(40) << nombre << right << setw(3) << escala;
}

