

/* 
 * File:   Estantes.cpp
 * Author: andre
 * 
 * Created on 7 de noviembre de 2024, 11:56
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Estantes.h"

Estantes::Estantes() {
    codigo = nullptr;
    anchura = 0;
    altura = 0;
    espacios = nullptr;
    pesoSoportado = 0.0;
    pesoActual = 0.0;
}

Estantes::~Estantes() {
    if (codigo != nullptr)delete[]codigo;
    if (espacios != nullptr)delete[]espacios;
}

void Estantes::SetPesoActual(double pesoActual) {
    this->pesoActual = pesoActual;
}

double Estantes::GetPesoActual() const {
    return pesoActual;
}

void Estantes::SetPesoSoportado(double pesoSoportado) {
    this->pesoSoportado = pesoSoportado;
}

double Estantes::GetPesoSoportado() const {
    return pesoSoportado;
}

void Estantes::SetAltura(int altura) {
    this->altura = altura;
}

int Estantes::GetAltura() const {
    return altura;
}

void Estantes::SetAnchura(int anchura) {
    this->anchura = anchura;
}

int Estantes::GetAnchura() const {
    return anchura;
}

void Estantes::SetCodigo(const char* cad) {
    if (codigo != nullptr)delete[]codigo;
    codigo = new char[strlen(cad) + 1];
    strcpy(codigo, cad);

}

void Estantes::GetCodigo(char *cad) const {
    if (codigo == nullptr)cad[0] = 0;
    else strcpy(cad, codigo);
}
//H, AAA, 6, 4
//V, BBB,  4, 6

void Estantes::leerDatosEstante(ifstream &arch) {
    char buffCodigo[10], c;

    arch.getline(buffCodigo, 10, ',');
    SetCodigo(buffCodigo);
    arch >> anchura >> c >> altura;
    int cantEspEst = anchura*altura;

    espacios = new class Espacio[cantEspEst];
    for (int x = 0; x < anchura; x++) {
        for (int y = 0; y < altura; y++) {
            cout << "(" << x << "," << y << ")";
            espacios[anchura * y + x].SetPosx(x);
            espacios[anchura * y + x].SetPosy(y);
        }
    }
}