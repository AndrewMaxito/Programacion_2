
/* 
 * File:   Biblioteca.cpp
 * Author: andre
 * 
 * Created on 30 de octubre de 2024, 11:50
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Biblioteca.h"

Biblioteca::Biblioteca() {
    cantidad_estantes =0;
    cantidad_libros =0;
}



Biblioteca::~Biblioteca() {
}

void Biblioteca::SetCantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

int Biblioteca::GetCantidad_libros() const {
    return cantidad_libros;
}

void Biblioteca::SetCantidad_estantes(int cantidad_estantes) {
    this->cantidad_estantes = cantidad_estantes;
}

int Biblioteca::GetCantidad_estantes() const {
    return cantidad_estantes;
}

