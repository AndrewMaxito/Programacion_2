

/* 
 * File:   ProductoEntregado.cpp
 * Author: alulab14
 * 
 * Created on 25 de octubre de 2024, 04:25 PM
 */

#include <cstring>
using namespace std;

#include "ProductoEntregado.h"

ProductoEntregado::ProductoEntregado() {
    codigo = nullptr;
    precio = 0.0;
}



ProductoEntregado::~ProductoEntregado() {
    if (codigo != nullptr) delete[] codigo;//destruir el ultimo valor 
}

void ProductoEntregado::SetPrecio(double precio) {
    this->precio = precio;
}

double ProductoEntregado::GetPrecio() const {
    return precio;
}

void ProductoEntregado::SetCodigo(const char* cad) {
    if (codigo != nullptr) delete[] codigo;
    codigo = new char[strlen(cad)+1];
    strcpy(codigo,cad);
}

void ProductoEntregado::GetCodigo(char *cad) const {
    if (codigo == nullptr) cad[0] = 0; // si no se le ha asignado algun valor devuleve un 0 como primer valor de la cadena
    else strcpy(cad,codigo);
}

