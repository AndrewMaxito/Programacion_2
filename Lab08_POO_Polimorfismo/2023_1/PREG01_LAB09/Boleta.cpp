
/* 
 * File:   Boleta.cpp
 * Author: andre
 * 
 * Created on 11 de junio de 2024, 18:20
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Boleta.h"
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"

Boleta::Boleta() {
    pboleta = nullptr;
}

Boleta::~Boleta() {
    if (pboleta != nullptr)delete pboleta;
}

void Boleta::leer(ifstream &arch) {
    char tipo;
    arch >> tipo;
    if (arch.eof())return;
    arch.get();
    switch (tipo) {
        case 'P':
            pboleta = new class Presencial;
            break;
        case 'S':
            pboleta = new class Semipresencial;
            break;
        case 'V':
            pboleta = new class Virtual;
            break;
    }
    pboleta->leer(arch); //Metodo Polimorfico
}
bool Boleta::existe() const{
    if (pboleta != nullptr )return true;
    else return false;
}

void Boleta::mostrar(ofstream &arch){
    
    
    
}

//
void operator>>(ifstream &arch, class Boleta &boleta) {
    boleta.leer(arch);
}

