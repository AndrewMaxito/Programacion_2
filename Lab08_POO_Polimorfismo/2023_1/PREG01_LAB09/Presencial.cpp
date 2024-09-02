

/* 
 * File:   Presencial.cpp
 * Author: andre
 * 
 * Created on 11 de junio de 2024, 18:19
 */
#include <iostream>
#include <iomanip>
#include <fstream>
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

void Presencial::leer(ifstream &arch) {
    char nombre[100], c;
    int codigo, escala;
    double creditos, recargo;
    arch >> codigo;
    arch.get();
    arch.getline(nombre, 100, ',');
    arch >> escala >> c >> creditos >> c >> recargo;

    //
    Alumno::SetCodigo(codigo);
    Alumno::SetCreditos(creditos);
    Alumno::SetEscala(escala);
    Alumno::SetNombre(nombre);
    SetRecargo(recargo);

}

void Presencial::imprime(ofstream &arch) {

    char nombre[100];
    Alumno::GetNombre(nombre);
    arch << left << setw(20) << Alumno::GetCodigo() << setw(40) << nombre << setw(10) << Alumno::GetEscala()
            << setw(10) << Alumno::GetCreditos() << setw(20) << " " << Alumno::GetTotal() << endl;

}
