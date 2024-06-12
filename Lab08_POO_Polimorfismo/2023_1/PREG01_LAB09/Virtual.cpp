

/* 
 * File:   Virtual.cpp
 * Author: andre
 * 
 * Created on 11 de junio de 2024, 18:19
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>

#include "Virtual.h"

Virtual::Virtual() {
    licencia = nullptr;
    total = 0.0;
}

Virtual::~Virtual() {
    if (licencia != nullptr)delete[] licencia;
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(const char* cad) {
    if (licencia != nullptr)delete[] licencia;
    licencia = new char [strlen(cad) + 1];
    strcpy(licencia, cad);
}

void Virtual::GetLicencia(char *cad) const {
    if (licencia == nullptr)cad[0] = 0;
    else strcpy(cad, licencia);
}


void Virtual::leer(ifstream &arch){
    char nombre[100],lic[100],c;
    int codigo,escala;
    double creditos;
    arch >> codigo;
    arch.get();
    arch.getline(nombre,100,',');
    arch >> escala >> c >> creditos;
    arch.get();
    arch.getline(lic,100,'\n');
    
    //
    Alumno::SetCodigo(codigo);
    Alumno::SetCreditos(creditos);
    Alumno::SetEscala(escala);
    Alumno::SetNombre(nombre);
    SetLicencia(lic);
}

void Virtual::imprime(ofstream &arch){
    
    char nombre[100],licencia[100];
    Alumno::GetNombre(nombre);
    GetLicencia(licencia);
    arch << left << setw(20) << Alumno::GetCodigo() << setw(40) << nombre << setw(10) << Alumno::GetEscala()
            << setw(10) << Alumno::GetCreditos() << setw(20) << licencia << Alumno::GetTotal() << endl;
    
}

