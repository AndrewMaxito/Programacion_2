
/* 
 * File:   Presencial.cpp
 * Author: andre
 * 
 * Created on 5 de noviembre de 2024, 16:27
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Presencial.h"

Presencial::Presencial() {
    recargo = 0.0;
    total = 0.0;
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

//

void Presencial::leerDatos(ifstream &arch) {
    Alumno::leerDatos(arch);
    arch >> recargo;
}

void Presencial::actualiza(double monto) {
    
    total = monto * GetRecargo() / 100;
    Alumno::SetTotal(monto + total);
}
void Presencial::imprime(ofstream& arch) {
    Alumno::imprime(arch);
    arch << right << setw(15) << "+" << setw(10) << Alumno::GetTotal() << endl;
}

