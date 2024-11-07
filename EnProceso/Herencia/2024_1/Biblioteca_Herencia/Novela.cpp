
/* 
 * File:   Novela.cpp
 * Author: andre
 * 
 * Created on 7 de noviembre de 2024, 11:50
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Novela.h"

Novela::Novela() {
    tipo = nullptr;
    peso = 0.0;
}

Novela::~Novela() {
    if (tipo != nullptr)delete[]tipo;
}

void Novela::SetPeso(double peso) {
    this->peso = peso;
}

double Novela::GetPeso() const {
    return peso;
}

void Novela::SetTipo(const char* cad) {
    if (tipo != nullptr)delete[]tipo;
    tipo = new char[strlen(cad)+1];
    strcpy(tipo,cad);
}

void Novela::GetTipo(char *cad) const {
    if (tipo == nullptr)cad[0] =0;
    else strcpy(cad,tipo);
}
//N, ABC123, El libro de la Selva, 2, 5, Aventura, 0.75
void Novela::leerDatosNovela(ifstream &arch){
    char buffTipo[30];
    Libro::leerDatos(arch);
    arch >> ws;
    arch.getline(buffTipo,30,',');
    SetTipo(buffTipo);
    arch >> peso;
}
