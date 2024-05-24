
/* 
 * File:   Producto.cpp
 * Author: andre
 * 
 * Created on 22 de mayo de 2024, 19:00
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

#include "Producto.h"
#include "Pedido.h"
#include "Cliente.h"

Producto::Producto() {
    codigo = nullptr;
    descripcion = nullptr;
    precio = 0.0;
    stock = 0;
    cantidad_clientes_servidos = 0;
    cantidad_clientes_no_servidos = 0;
}

Producto::~Producto() {
    if (codigo != nullptr) delete[]codigo;
    if (descripcion != nullptr) delete[]descripcion;
}

void Producto::SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos) {
    this->cantidad_clientes_no_servidos = cantidad_clientes_no_servidos;
}

int Producto::GetCantidad_clientes_no_servidos() const {
    return cantidad_clientes_no_servidos;
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
    if (descripcion != nullptr) delete[] descripcion;
    descripcion = new char [strlen(cad) + 1];
    strcpy(descripcion, cad);
}

void Producto::GetDescripcion(char *cad) const {
    if (descripcion == nullptr)cad[0] = 0;
    else strcpy(cad, descripcion);
}

void Producto::SetCodigo(const char* cad) {
    if (codigo != nullptr) delete[] codigo;
    codigo = new char [strlen(cad) + 1];
    strcpy(codigo, cad);
}

void Producto::GetCodigo(char *cad) const {
    if (codigo == nullptr)cad[0] = 0;
    else strcpy(cad, codigo);
}

bool operator>>(ifstream&arch, class Producto &pro) {
    char codigoP[8], descripcionP[100], c;
    double precioP;
    int stockP;

    arch.getline(codigoP, 8, ',');
    if (arch.eof()) return false;
    arch.getline(descripcionP, 100, ',');
    arch >> precioP >> c >> stockP;
    arch.get(); //salto de linea

    //

    pro.SetCodigo(codigoP);
    pro.SetDescripcion(descripcionP);
    pro.SetPrecio(precioP);
    pro.SetStock(stockP);
    return true;
}

bool Producto::operator+=(const class Pedido& ped) {
    if (stock > 0) {
        stock--;
        if (cantidad_clientes_servidos < 200) {
            clientes_servidos[cantidad_clientes_servidos] = ped.GetDni_cliente();
            cantidad_clientes_servidos++;
            return true;
        }
    } else {
        if (cantidad_clientes_no_servidos < 200) {
            clientes_no_servidos[cantidad_clientes_no_servidos] = ped.GetDni_cliente();
            cantidad_clientes_no_servidos++;
            return false;
        }
    }
}


void operator<<(ostream &os, const Producto &prod) {
    char codigoP[8],descrip[100];
    prod.GetCodigo(codigoP);
    prod.GetDescripcion(descrip);
    
    os << left << setw(10) << codigoP << " "
       << setw(50) << descrip << " "
       << fixed << setprecision(2) << right << setw(10) << prod.GetPrecio() << " "
       << setw(5) <<prod.GetStock() << "  Clientes atendidos: ";

    if (prod.GetCantidad_clientes_servidos() == 0) {
        os << "NO SE ATENDIERON PEDIDOS";
    } else {
        for (int i = 0; i < prod.GetCantidad_clientes_servidos(); ++i) {
            os << prod.metodoGAA(i) << " ";
        }
    }
    os << endl;

    os << "Clientes no atendidos: ";

    if (prod.GetCantidad_clientes_no_servidos() == 0) {
        os << "NO HAY CLIENTES SIN ATENDER";
    } else {
        for (int i = 0; i < prod.GetCantidad_clientes_no_servidos(); ++i) {
            os << prod.metodoRAAA(i) << " ";
        }
    }
    os<<endl;
}

int  Producto::metodoGAA(int i)const {
    return clientes_servidos[i];
}

int  Producto::metodoRAAA(int i)const {
    return clientes_no_servidos[i];
}