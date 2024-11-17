

/* 
 * File:   Enciclopedia.cpp
 * Author: andre
 * 
 * Created on 17 de noviembre de 2024, 12:35 PM
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#include "Enciclopedia.h"

Enciclopedia::Enciclopedia() {
    sku = 0;
    anho = 0;
    vigencia = 1;
}
void Enciclopedia::lee(ifstream& arch) {
    Libro::lee(arch);
    char c;
    arch >> sku >> c >> anho;
}

void Enciclopedia::actualiza() {
    if (anho <= 2020) vigencia = 0;
}

void Enciclopedia::imprime(ofstream& arch) {
    Libro::imprime(arch);
    arch << left << setw(6) << "SKU:" << setw(12) << sku << setw(7) << "AÑO:" <<
            setw(10) << anho << setw(14) << "Vigencia: " << vigencia << endl;
}



