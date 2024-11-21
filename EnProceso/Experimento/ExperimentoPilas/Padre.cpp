
/* 
 * File:   Padre.cpp
 * Author: andre
 * 
 * Created on 20 de noviembre de 2024, 09:45 PM
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Padre.h"

Padre::Padre() {
    nombrePadre = nullptr;
}

Padre::Padre(const Padre& orig) {
}

Padre::~Padre() {
    if (nombrePadre!=nullptr)delete[]nombrePadre;
}



void Padre::setNombrePadre(const char* cad) {
    if (nombrePadre != nullptr)delete[]nombrePadre;
    nombrePadre = new char [strlen(cad)+1];
    strcpy(nombrePadre,cad);
}

void Padre::getNombrePadre(char *cad) const {
    if (nombrePadre == nullptr)cad[0] =0;
    else strcpy(cad,nombrePadre);
}

void Padre::setCodigoPadre(int codigoPadre) {
    this->codigoPadre = codigoPadre;
}

int Padre::getCodigoPadre() const {
    return codigoPadre;
}
void Padre::leer(ifstream &arch) {
    char cad[100],c;
    arch >> codigoPadre >> c;
    arch.getline(cad,100,',');
    setNombrePadre(cad);
}

