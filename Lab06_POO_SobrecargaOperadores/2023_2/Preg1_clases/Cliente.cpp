/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.cpp
 * Author: alulab14
 * 
 * Created on 25 de octubre de 2024, 04:42 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Cliente.h"
#include "Pedido.h"


Cliente::Cliente() {
    dni = 0;
    nombre = nullptr;
    telefono = 0;
    cantidad_productos_entregados = 0;
    monto_total = 0.0;
}

Cliente::~Cliente() {
    if (nombre != nullptr) delete[] nombre;
}

void Cliente::SetMonto_total(double monto_total) {
    this->monto_total = monto_total;
}

double Cliente::GetMonto_total() const {
    return monto_total;
}

void Cliente::SetCantidad_productos_entregados(int cantidad_productos_entregados) {
    this->cantidad_productos_entregados = cantidad_productos_entregados;
}

int Cliente::GetCantidad_productos_entregados() const {
    return cantidad_productos_entregados;
}

void Cliente::SetTelefono(int telefono) {
    this->telefono = telefono;
}

int Cliente::GetTelefono() const {
    return telefono;
}

void Cliente::SetNombre(const char* cad) {
    if (nombre != nullptr)delete[] nombre;
    nombre = new char [strlen(cad) + 1];
    strcpy(nombre, cad);
}

void Cliente::GetNombre(char *cad) const {
    if (nombre == nullptr) cad[0] = 0;
    else strcpy(cad, nombre);
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

bool operator>>(ifstream &arch, class Cliente &cli) {
    //79464412,PORTUGAL RAFFO ALEXANDER,3902394
    int dni, telefono;
    char nombre[100], c;
    arch >> dni;
    if (arch.eof())return false;
    arch.get();
    arch.getline(nombre, 100, ',');
    arch >> telefono;

    //
    cli.SetDni(dni);
    cli.SetNombre(nombre);
    cli.SetTelefono(telefono);
    return true;
}

void Cliente::operator+=(const class Pedido &ped) {
    char codigoPed[10];
    ped.GetCodigo(codigoPed);
    productos_entregados[cantidad_productos_entregados].SetCodigo(codigoPed);
    productos_entregados[cantidad_productos_entregados].SetPrecio(ped.GetPrecio_producto());
    cantidad_productos_entregados++;
    monto_total += ped.GetPrecio_producto();
}

void operator << (ofstream &arch, const class Cliente &cli){
    char nombre[100];
    cli.GetNombre(nombre);
    
    arch << left << setw(15)<< cli.GetDni() << setw(60) << nombre << setw(15) <<
            cli.GetMonto_total() << setw(20) << "Productos entregados: ";
    
    if (cli.GetCantidad_productos_entregados() != 0) {
        
        for (int i = 0; i < cli.GetCantidad_productos_entregados(); i++) {
            char codigo[10];
            cli.metodoObtennerProdEntregados(i,codigo);
            arch << codigo << " ";
        }
    } else {
        arch << "NO SE LE ENTREGARON PRODUCTOS" <<endl;
    }
    arch <<endl;
}

void Cliente::metodoObtennerProdEntregados(int pos,char *cad)const {
    productos_entregados[pos].GetCodigo(cad);
}
