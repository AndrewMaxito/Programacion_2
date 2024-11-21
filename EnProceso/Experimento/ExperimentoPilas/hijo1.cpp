
/* 
 * File:   hijo1.cpp
 * Author: andre
 * 
 * Created on 20 de noviembre de 2024, 09:46 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "hijo1.h"

hijo1::hijo1() {
    carHijo1 = nullptr;
}

hijo1::hijo1(const hijo1& orig) {
}

hijo1::~hijo1() {
    if (carHijo1 != nullptr)delete[]carHijo1;
}



void hijo1::setNumerohijo1(int numerohijo1) {
    this->numerohijo1 = numerohijo1;
}

int hijo1::getNumerohijo1() const {
    return numerohijo1;
}

void hijo1::setCarHijo1(const char* cad) {
    if (carHijo1 != nullptr)delete[]carHijo1;
    carHijo1 = new char [strlen(cad)+1];
    strcpy(carHijo1,cad);
}

void hijo1::getCarHijo1(char *cad) const {
    if (carHijo1 == nullptr)cad[0]=0;
    else strcpy(cad,carHijo1);
}

void hijo1::leer(ifstream& arch) {
    Padre::leer(arch);
    char cad[100],c;
    arch.getline(cad,100,',');
    //
    setCarHijo1(cad);
    arch >> numerohijo1;
}