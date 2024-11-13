

/* 
 * File:   Deudor.cpp
 * Author: andre
 * 
 * Created on 12 de noviembre de 2024, 14:46
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Deudor.h"
#include "ClienteA.h"
#include "ClienteB.h"
#include "ClienteC.h"

Deudor::Deudor() {
    Cdeudor = nullptr;
}

Deudor::Deudor(const Deudor& orig) {
}

Deudor::~Deudor() {
    if (Cdeudor != nullptr)delete Cdeudor;
}

void Deudor::cargarDatos(char catego,ifstream &arch){
    switch (catego){
        case 'A':
            Cdeudor = new ClienteA;
            break;
        case 'B':
            Cdeudor = new ClienteB;
            break;
        case 'C':
            Cdeudor = new ClienteC;
            break;
    }
    Cdeudor->lee(arch,catego);
}


bool operator >> (ifstream &arch,Deudor &deudor){
    char catego;
    arch >> catego;
    if (arch.eof())return false;
    arch.get();//coma
    deudor.cargarDatos(catego,arch);
    return true;
}

void Deudor::muestraDatosDeudor(ofstream &arch){
    Cdeudor->imprime(arch,0,0);
}

bool Deudor::existe(){
    if (Cdeudor != nullptr) return true;
    return false;
}

int Deudor::getCodDni(){
    return Cdeudor->GetDni();
}
void Deudor::actualizadeudor(double monto){
    Cdeudor->calcula(monto);
}
