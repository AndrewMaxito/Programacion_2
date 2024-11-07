
/* 
 * File:   Libro.cpp
 * Author: andre
 * 
 * Created on 7 de noviembre de 2024, 11:39
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
    peso = 0.0;
    colocado = false;
}

Libro::~Libro() {
    if (codigo != nullptr)delete[]codigo;
    if (nombre != nullptr)delete[]nombre;
}

void Libro::SetColocado(bool colocado) {
    this->colocado = colocado;
}

bool Libro::IsColocado() const {
    return colocado;
}

void Libro::SetPeso(double peso) {
    this->peso = peso;
}

double Libro::GetPeso() const {
    return peso;
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
    if (nombre != nullptr)delete[]nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Libro::GetNombre(char *cad) const {
    if (nombre == nullptr)cad[0] =0;
    else strcpy(cad,nombre);
}

void Libro::SetCodigo(const char* cad) {
    if (codigo != nullptr)delete[]codigo;
    codigo = new char[strlen(cad)+1];
    strcpy(codigo,cad);
}

void Libro::GetCodigo(char *cad) const {
    if (codigo == nullptr)cad[0] =0;
    else strcpy(cad,codigo);
}

//E, EFG333, La enciclopedia de la Resurreccion, 6, 6, 3, 8.7
void Libro::leerDatos(ifstream &arch){
    char buffCodigo[20],buffNombre[100],c;
    
    arch.getline(buffCodigo,20,',');
    arch >> ws;
    SetCodigo(buffCodigo);
    arch.getline(buffNombre,100,',');
    SetNombre(buffNombre);
    
    arch >> ancho >> c >>alto >> c;
}


