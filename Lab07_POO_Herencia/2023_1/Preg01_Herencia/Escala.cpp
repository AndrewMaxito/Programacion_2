

/* 
 * File:   Escala.cpp
 * Author: andre
 * 
 * Created on 5 de noviembre de 2024, 16:25
 */

#include "Escala.h"

Escala::Escala() {
    codigo =0;
    precio = 0.0;
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




