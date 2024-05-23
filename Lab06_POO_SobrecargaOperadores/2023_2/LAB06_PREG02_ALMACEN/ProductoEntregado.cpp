
/* 
 * File:   ProductoEntregado.cpp
 * Author: andre
 * 
 * Created on 22 de mayo de 2024, 18:53
 */

#include <cstring>
#include "ProductoEntregado.h"

ProductoEntregado::ProductoEntregado() {
    codigo = nullptr;
    precio = 0.0;
}

ProductoEntregado::~ProductoEntregado() {
    if (codigo != nullptr) delete[]codigo;
}

void ProductoEntregado::SetPrecio(double precio) {
    this->precio = precio;
}

double ProductoEntregado::GetPrecio() const {
    return precio;
}

void ProductoEntregado::SetCodigo(const char* cad) {
    if (codigo != nullptr) delete[] codigo;
    codigo = new char [strlen(cad) + 1];
    strcpy(codigo, cad);
}

void ProductoEntregado::GetCodigo(char *cad) const {
    if (codigo == nullptr)cad[0] = 0;
    else strcpy(cad, codigo);
}


