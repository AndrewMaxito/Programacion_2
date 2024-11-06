
/* 
 * File:   Virtual.cpp
 * Author: andre
 * 
 * Created on 5 de noviembre de 2024, 16:31
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Virtual.h"

Virtual::Virtual() {
    licencia = nullptr;
    total = 100;
}

Virtual::~Virtual() {
    if (licencia != nullptr)delete[]licencia;
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(const char* cad) {
    licencia = new char [strlen(cad)+1];
    strcpy(licencia,cad);
}

void Virtual::GetLicencia(char *cad) const {
    if (licencia == nullptr)cad[0] = 0;
    else strcpy(cad,licencia);
}

void Virtual::leerDatos(ifstream &arch){
    char buffLicencia[20];
    Alumno::leerDatos(arch);
    arch.getline(buffLicencia,20);
    SetLicencia(buffLicencia);
}

void Virtual:: actualiza(double monto){
    Alumno::SetTotal(monto + total);
}

void Virtual::imprime(ofstream& arch) {
    Alumno::imprime(arch);
    arch << right << setw(15) << licencia << setw(10) << Alumno::GetTotal() << endl;
}