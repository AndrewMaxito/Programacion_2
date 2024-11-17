

/* 
 * File:   ClienteA.cpp
 * Author: andre
 * 
 * Created on 12 de noviembre de 2024, 14:38
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#include "ClienteA.h"

ClienteA::ClienteA() {
    descuento = 0;
}

void ClienteA::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double ClienteA::GetDescuento() const {
    return descuento;
}

void ClienteA::lee(ifstream &arch, char catego) {
    arch >> descuento;
    arch.get();//coma
    Cliente::lee(arch,catego);
}

void ClienteA::imprime(ofstream &arch, double descuento, double flete){
    Cliente::imprime(arch,descuento,0);
}

void ClienteA::calcula(double monto){
    SetTotalPed(GetTotalPed()+monto*(1-(descuento/100)));
    SetCantPed(GetCantPed()+1);
}