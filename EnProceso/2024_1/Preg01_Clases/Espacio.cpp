
/* 
 * File:   Espacio.cpp
 * Author: andre
 * 
 * Created on 30 de octubre de 2024, 11:28
 */

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




