

/* 
 * File:   Cliente.cpp
 * Author: andre
 * 
 * Created on 22 de mayo de 2024, 18:55
 */

#include <cstring>
#include <iostream>
#include <iomanip>
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
    if (nombre != nullptr) delete[] nombre;
    nombre = new char [strlen(cad) + 1];
    strcpy(nombre, cad);
}

void Cliente::GetNombre(char *cad) const {
    if (nombre == nullptr)cad[0] = 0;
    else strcpy(cad, nombre);
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

bool operator>>(ifstream&arch, class Cliente &cli) {
    int dni, telefono;
    char nombreC[100], c;
    arch >> dni;
    if (arch.eof()) return false;
    arch.get(); //solo la coma 
    arch.getline(nombreC, 100, ',');
    arch >> telefono;

    //
    cli.SetDni(dni);
    cli.SetNombre(nombreC);
    cli.SetTelefono(telefono);
    return true;
}

void Cliente::operator+=(const class Pedido& ped) {
    int contador = 0;
    char codigo[8];
    ped.GetCodigo(codigo);
    if (cantidad_productos_entregados < 300) {
        productos_entregados[cantidad_productos_entregados].SetCodigo(codigo);
        productos_entregados[cantidad_productos_entregados].SetPrecio(ped.GetPrecio_producto());
        cantidad_productos_entregados++;
        monto_total += ped.GetPrecio_producto();
    }
}


void operator << (ofstream&arch,const class Cliente &cli){
    char nombre[100];
    cli.GetNombre(nombre);
     arch << setw(8) << cli.GetDni() << left << setw(5)<<' ' <<setw(60) << nombre << "  "  << right 
             << setw(15) << cli.GetTelefono() << "  "  << fixed << setprecision(2) << setw(15) << 
             cli.GetMonto_total() << setw(35) << " Productos entregados: ";

    if (cli.GetCantidad_productos_entregados() == 0) {
        arch << "NO SE LE ENTREGARON PRODUCTOS"<<endl;
    } else {
        char codigo[8];
        for (int i = 0; i < cli.GetCantidad_productos_entregados(); ++i) {
            cli.metodo(i,codigo);
            arch << codigo << "   ";
        }
        arch<<endl;
    }
}

void Cliente::metodo(int i,char*cad)const {
    productos_entregados[i].GetCodigo(cad);
}
