

/* 
 * File:   Escala.cpp
 * Author: andre
 * 
 * Created on 27 de mayo de 2024, 18:29
 */

#include "Escala.h"

Escala::Escala() {
    codigo=0;
    precio=0;
}


void Escala::SetPrecio(double precio) {
    this->precio = precio;
}

double Escala::GetPrecio() const {
    return precio;
}

void Escala::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Escala::GetCodigo() const {
    return codigo;
}

