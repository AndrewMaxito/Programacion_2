
/* 
 * File:   hijo2.cpp
 * Author: andre
 * 
 * Created on 20 de noviembre de 2024, 09:46 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "hijo2.h"

hijo2::hijo2() {
    carHijo2 = nullptr;
}

hijo2::hijo2(const hijo2& orig) {
}

hijo2::~hijo2() {
    if (carHijo2 != nullptr)delete[]carHijo2;
}


void hijo2::setNumerohijo2(int numerohijo2) {
    this->numerohijo2 = numerohijo2;
}

int hijo2::getNumerohijo2() const {
    return numerohijo2;
}

void hijo2::setCarHijo2(const char* cad) {
    if (carHijo2 != nullptr)delete[]carHijo2;
    carHijo2 = new char [strlen(cad)+1];
    strcpy(carHijo2,cad);
}

void hijo2::getCarHijo2(char *cad) const {
    if (carHijo2 == nullptr)cad[0]=0;
    else strcpy(cad,carHijo2);
}

void hijo2::leer(ifstream& arch) {
    Padre::leer(arch);
    char cad[100],c;
    arch.getline(cad,100,',');
    //
    setCarHijo2(cad);
    arch >> numerohijo2;
}
