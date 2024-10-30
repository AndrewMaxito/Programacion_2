
/* 
 * File:   Producto.cpp
 * Author: alulab14
 * 
 * Created on 25 de octubre de 2024, 04:57 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Producto.h"
#include "Cliente.h"

Producto::Producto() {
    codigo = nullptr;
    descripcion = nullptr;
    precio = 0.0;
    stock = 0;
    cantidad_clientes_servidos = 0;
    cantidad_no_clientes_servidos = 0;
}

Producto::~Producto() {
    if (codigo != nullptr)delete[]codigo;
    if (descripcion != nullptr)delete[]descripcion;
}

void Producto::SetCantidad_no_clientes_servidos(int cantidad_no_clientes_servidos) {
    this->cantidad_no_clientes_servidos = cantidad_no_clientes_servidos;
}

int Producto::GetCantidad_no_clientes_servidos() const {
    return cantidad_no_clientes_servidos;
}

void Producto::SetCantidad_clientes_servidos(int cantidad_clientes_servidos) {
    this->cantidad_clientes_servidos = cantidad_clientes_servidos;
}

int Producto::GetCantidad_clientes_servidos() const {
    return cantidad_clientes_servidos;
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::SetDescripcion(const char* cad) {
    if (descripcion != nullptr)delete[]descripcion;
    descripcion = new char [strlen(cad) + 1];
    strcpy(descripcion, cad);
}

void Producto::GetDescripcion(char *cad) const {
    if (descripcion == nullptr)cad[0] = 0;
    else strcpy(cad, descripcion);
}

void Producto::SetCodigo(const char* cad) {
    if (codigo != nullptr)delete[]codigo;
    codigo = new char [strlen(cad) + 1];
    strcpy(codigo, cad);
}

void Producto::GetCodigo(char *cad) const {
    if (codigo == nullptr)cad[0] = 0;
    else strcpy(cad, codigo);
}

bool operator>>(ifstream &arch, class Producto &prod) {

    //BIT-434,Campana Extractora modelo Glass,375.09,10
    char codigo[10], nombre[100], c;
    double precio;
    int stock;

    arch.getline(codigo, 10, ',');
    if (arch.eof()) return false;
    arch.getline(nombre, 100, ',');
    arch >> precio >> c >>stock;
    arch.get(); //salto de linea

    //
    prod.SetCodigo(codigo);
    prod.SetDescripcion(nombre);
    prod.SetPrecio(precio);
    prod.SetStock(stock);
    return true;
}

bool Producto::operator+=(class Pedido &ped) {
    ped.SetPrecio_producto(precio); 
    if (stock > 0) {
        //asumendo que nunca se llenaran los 200 espacios 
        clientes_servidos[cantidad_clientes_servidos] = ped.GetDni_cliente();
        cantidad_clientes_servidos++;
        stock--;
        return true;
    } else {
        clientes_no_servidos[cantidad_no_clientes_servidos] = ped.GetDni_cliente();
        cantidad_no_clientes_servidos++;
        return false;
    }
}

void operator << (ofstream &arch, const class Producto &prod){
    char codigo[10],nombre[100];
    prod.GetCodigo(codigo);
    prod.GetDescripcion(nombre);
    arch << left << setw(10) << codigo << setw(60) << nombre << setw(15) << 
            prod.GetPrecio() << prod.GetStock() << endl;
    
    if (prod.GetCantidad_clientes_servidos() != 0) {
        arch << "Clientes atendidos:  ";
        for (int i = 0; i < prod.GetCantidad_clientes_servidos(); i++) {
            arch << prod.metodoGetDniAtendido(i) << "   ";
        }
    } else arch << "No se atendieron Pedidos"<<endl;
    arch << endl;
    if (prod.GetCantidad_no_clientes_servidos() != 0) {
        arch << "Clientes NO atendidos:  ";
        for (int i = 0; i < prod.GetCantidad_no_clientes_servidos(); i++) {
            arch << prod.metodoGetDniNoAtendidos(i)<< "   ";
        }
        arch << endl;
    } else arch << "No hay clientes sin atender" << endl;
    arch <<endl;
}

int Producto::metodoGetDniAtendido(int pos)const {
    return clientes_servidos[pos];
}
int Producto::metodoGetDniNoAtendidos(int pos)const {
    return clientes_no_servidos[pos];
}