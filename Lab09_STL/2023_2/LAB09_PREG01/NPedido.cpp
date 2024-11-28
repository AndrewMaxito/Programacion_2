

/* 
 * File:   NPedido.cpp
 * Author: andre
 * 
 * Created on 27 de noviembre de 2024, 08:52 PM
 */
#include <iomanip>
#include <iostream>
#include <cstring>
#include "NPedido.h"
using namespace std;

NPedido::NPedido() {
    codigo = nullptr;
    cantidad = 0;
    peso = 0.0;
}

NPedido::NPedido(const NPedido& orig) {
    codigo = nullptr;
    *this = orig;
}

NPedido::~NPedido() {
    if (codigo != nullptr)delete[]codigo;
}

void NPedido::SetCodigo(const char* cad) {
    if (codigo != nullptr)delete[] codigo;
    codigo = new char [strlen(cad) + 1];
    strcpy(codigo, cad);
}

void NPedido::GetCodigo(char *cad) const {
    if (codigo == nullptr)cad[0] = 0;
    else strcpy(cad, codigo);
}

void NPedido::leerDatosVehiculo(ifstream &arch) {
    char cad[100], c;
    arch.getline(cad, 100, ',');
    SetCodigo(cad);
    arch >> cantidad >> c >> peso;
}

void NPedido::SetPeso(double peso) {
    this->peso = peso;
}

double NPedido::GetPeso() const {
    return peso;
}

void NPedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int NPedido::GetCantidad() const {
    return cantidad;
}

void NPedido::operator=(const NPedido& right) {
    if (codigo != nullptr)delete[]codigo;
    SetCodigo(right.codigo);
    cantidad = right.cantidad;
    peso = right.peso;
}

void NPedido::imprimirDatosCamion(ofstream& arch) const {
    arch << left << setw(15) << codigo << setw(10) << cantidad << right <<
            setw(7) << peso << endl;
}