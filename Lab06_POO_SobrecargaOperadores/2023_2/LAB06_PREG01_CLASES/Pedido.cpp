
/* 
 * File:   Pedido.cpp
 * Author: andre
 * 
 * Created on 22 de mayo de 2024, 19:04
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

#include "Pedido.h"

Pedido::Pedido() {
    codigo=nullptr;
    dni_cliente=0;
    precio_producto=0.0;
}

Pedido::~Pedido() {
    if (codigo != nullptr)delete[] codigo;
}

void Pedido::SetPrecio_producto(double precio_producto) {
    this->precio_producto = precio_producto;
}

double Pedido::GetPrecio_producto() const {
    return precio_producto;
}

void Pedido::SetDni_cliente(int dni_cliente) {
    this->dni_cliente = dni_cliente;
}

int Pedido::GetDni_cliente() const {
    return dni_cliente;
}

void Pedido::SetCodigo(const char* cad) {
    if (codigo != nullptr) delete[] codigo;
    codigo = new char [strlen(cad) + 1];
    strcpy(codigo, cad);
}

void  Pedido::GetCodigo(char *cad) const {
    if (codigo == nullptr)cad[0] = 0;
    else strcpy(cad, codigo);
}

bool operator>>(ifstream&arch, class Pedido &ped){
    char codigoPed[8];
    int dni;
   
    arch.getline(codigoPed, 8, ',');
    if (arch.eof()) return false;
    arch >> dni;
    arch.get();
    
    //
    ped.SetCodigo(codigoPed);
    ped.SetDni_cliente(dni);
    return true;
}


