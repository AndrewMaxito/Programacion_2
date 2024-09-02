
/* 
 * File:   Presencial.cpp
 * Author: andre
 * 
 * Created on 27 de mayo de 2024, 18:32
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Presencial.h"

Presencial::Presencial() {
    recargo = 0;
    total = 0;
}

void Presencial::SetTotal(double total) {
    this->total = total;
}

double Presencial::GetTotal() const {
    return total;
}

void Presencial::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double Presencial::GetRecargo() const {
    return recargo;
}

void Presencial::leerDatos(ifstream& arch) {
    Alumno::leerDatos(arch);
    arch >> recargo;
    arch.get(); //descarta salto de linea 
}

void Presencial::actualiza(double monto) {
    total = monto * GetRecargo() / 100; //monto del recargo
    Alumno::SetTotal(monto + total); // se le pasa el monto mas el recargo
}

void Presencial::imprime(ofstream& arch) {
    Alumno::imprime(arch);
    arch << right << setw(15) << "+" << setw(10) << Alumno::GetTotal() << endl;
}

