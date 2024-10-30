

/* 
 * File:   Pedido.cpp
 * Author: alulab14
 * 
 * Created on 25 de octubre de 2024, 05:08 PM
 */
#include <fstream>
#include <cstring>
using namespace std;

#include "Pedido.h"

Pedido::Pedido() {
    codigo = nullptr;
    dni_cliente = 0;
    precio_producto = 0.0;
}

Pedido::~Pedido() {
    if (codigo != nullptr) delete[] codigo;
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
    if (codigo != nullptr)delete[]codigo;
    codigo = new char [strlen(cad)+1];
    strcpy(codigo,cad);
}

void Pedido::GetCodigo(char *cad) const {
    if (codigo == nullptr )cad[0]=0;
    else strcpy(cad,codigo);
}


bool operator>>(ifstream &arch, class Pedido &pedi){
    //JXD-139,50375303
    char codigo[10];
    int dni;
    arch.getline(codigo,10,',');
    if (arch.eof()) return false;
    arch >> dni;
    arch.get();//salto linea
    
    //
    pedi.SetCodigo(codigo);
    pedi.SetDni_cliente(dni);
    return true;
}
