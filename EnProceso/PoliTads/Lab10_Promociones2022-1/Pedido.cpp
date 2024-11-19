

/* 
 * File:   Pedido.cpp
 * Author: andre
 * 
 * Created on 19 de noviembre de 2024, 15:53
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Pedido.h"

Pedido::Pedido() {
    codigo = 0;
    nombre = nullptr;
    cantidad = 0;
    total = 0.0;
}


Pedido::~Pedido() {
    if (nombre != nullptr)delete[] nombre;
}

void Pedido::SetNombre(const char* cad) {
    if(nombre != nullptr)delete[] nombre;
    nombre = new char [strlen(cad)+1];
    strcpy(nombre,cad);
}

void Pedido::GetNombre(char *cad) const {
    if (nombre == nullptr)cad[0] = 0;
    else strcpy(cad,nombre);
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

void Pedido::lee(ifstream& arch, int codigo) {
    char nom[100],c;
    int dd,mm,aa;
    this->codigo = codigo;
    arch.getline(nom,100,',');
    SetNombre(nom);
    arch >> cantidad >> c >> total >> c >> dni >> c >> dd >> c >> mm >> c >> aa;
    fecha = aa*10000+mm*100+dd;
}

void Pedido::SetTotal(double total) {
    this->total = total;
}

double Pedido::GetTotal() const {
    return total;
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetDni(int dni) {
    this->dni = dni;
}

int Pedido::GetDni() const {
    return dni;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}




