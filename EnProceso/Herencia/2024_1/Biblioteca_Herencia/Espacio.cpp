

/* 
 * File:   Espacio.cpp
 * Author: andre
 * 
 * Created on 7 de noviembre de 2024, 11:54
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Espacio.h"

Espacio::Espacio() {
    contenido = 'D';
    posx = 0;
    posy = 0;
}

void Espacio::SetPosy(int posy) {
    this->posy = posy;
}

int Espacio::GetPosy() const {
    return posy;
}

void Espacio::SetPosx(int posx) {
    this->posx = posx;
}

int Espacio::GetPosx() const {
    return posx;
}

void Espacio::SetContenido(char contenido) {
    this->contenido = contenido;
}

char Espacio::GetContenido() const {
    return contenido;
}




