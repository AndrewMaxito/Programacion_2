
/* 
 * File:   Revista.cpp
 * Author: andre
 * 
 * Created on 17 de noviembre de 2024, 12:41 PM
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Revista.h"

Revista::Revista() {
    ISSN = 0;
    anho = 0;
    numero = 0;
    vigencia = 1;
}

void Revista::lee(ifstream& arch) {
    Libro::lee(arch);
    char c;
    arch >> ISSN >> c >> anho >> c >> numero;
}

void Revista::actualiza() {
    if (anho <= 2020) vigencia = 0;
}

void Revista::imprime(ofstream& arch) {
    Libro::imprime(arch);
    arch << left << setw(6) << "ISSN:" << setw(12) << ISSN << setw(7) << "AÑO:" <<
            setw(10) << anho << setw(14)<<"Numero:"<<setw(10)<<numero << 
            "Vigencia: " << vigencia << endl;
}




