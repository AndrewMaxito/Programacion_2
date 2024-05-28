
/* 
 * File:   Semipresencial.cpp
 * Author: andre
 * 
 * Created on 27 de mayo de 2024, 18:34
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Semipresencial.h"

Semipresencial::Semipresencial() {
    descueto = 0.0;
    total = 0.0;
}

void Semipresencial::leerDatos(ifstream& arch) {
    Alumno::leerDatos(arch);
    arch >> descueto;
    arch.get();
}

void Semipresencial::setTotal(double total) {
    this->total = total;
}

double Semipresencial::getTotal() const {
    return total;
}

void Semipresencial::setDescueto(double descueto) {
    this->descueto = descueto;
}

double Semipresencial::getDescueto() const {
    return descueto;
}

void Semipresencial::actualiza(double monto) {
    total = monto * getDescueto() / 100;
    Alumno::SetTotal(monto - total);
}

void Semipresencial::imprime(ofstream& arch){
    Alumno::imprime(arch);
    arch << right << setw(15) << "-" << setw(10) << Alumno::GetTotal() << endl;
}
