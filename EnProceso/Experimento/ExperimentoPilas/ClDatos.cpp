

/* 
 * File:   ClDatos.cpp
 * Author: andre
 * 
 * Created on 20 de noviembre de 2024, 09:42 PM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <string.h>
using namespace std;
#include "ClDatos.h"

ClDatos::ClDatos() {
    nombre = nullptr;
    objPadre = nullptr;
    codigo = 0;
}

ClDatos::ClDatos(const ClDatos& orig) {
    nombre = nullptr;
    objPadre = nullptr;
    *this = orig;
}

ClDatos::~ClDatos() {
    if (nombre != nullptr)delete[] nombre;
}

void ClDatos::operator=(const ClDatos& datos) {
    char cadena[100];
    codigo = datos.codigo;
    datos.GetNombre(cadena);
    SetNombre(cadena);
    objPadre = datos.objPadre; //aqui si copia la direccion de memoria
}

void ClDatos::SetNombre(const char* cad) {
    if (nombre != nullptr)delete nombre;
    nombre = new char [strlen(cad)+1];
    strcpy(nombre,cad);
}

void ClDatos::GetNombre(char* cad) const {
    if (nombre == nullptr)cad[0] = 0;
    else strcpy(cad,nombre);
}
