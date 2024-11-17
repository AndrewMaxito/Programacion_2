

/* 
 * File:   Pedido.cpp
 * Author: andre
 * 
 * Created on 12 de noviembre de 2024, 14:42
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Pedido.h"

Pedido::Pedido() {
    codigo = 0;
    cantidad = 0;
    dni = 0;
    fecha = 0;
    total = 0;
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

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}


bool operator >> (ifstream &arch,Pedido &ped){
    int cod,cant,dniR,fecha;
    double montoPed;
    int dd,mm,aa;
    char c;
    
    arch >> cod;
    if (arch.eof()) return false;
    arch >> c >> cant >> c >> montoPed >> c >> dniR >> c >> dd >> c >> mm >> 
            c >> aa;
    fecha = aa*10000+mm*100+dd;
    //
    
    ped.SetCodigo(cod);
    ped.SetCantidad(cant);
    ped.SetDni(dniR);
    ped.SetFecha(fecha);
    ped.SetTotal(montoPed);
    return true;
}
