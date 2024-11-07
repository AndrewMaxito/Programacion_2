

/* 
 * File:   Enciclopedia.cpp
 * Author: andre
 * 
 * Created on 7 de noviembre de 2024, 11:48
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Enciclopedia.h"

Enciclopedia::Enciclopedia() {
    volumen = 0;
    peso = 0.0;
}

void Enciclopedia::SetPeso(double peso) {
    this->peso = peso;
}

double Enciclopedia::GetPeso() const {
    return peso;
}

void Enciclopedia::SetVolumen(int volumen) {
    this->volumen = volumen;
}

int Enciclopedia::GetVolumen() const {
    return volumen;
}
void Enciclopedia::leeDatosEnciclopedia(ifstream &arch){
    char c;
    Libro::leerDatos(arch);
    arch >> volumen >> c >> peso;
}






