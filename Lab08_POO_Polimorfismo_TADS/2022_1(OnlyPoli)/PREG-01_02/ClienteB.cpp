
/* 
 * File:   ClienteB.cpp
 * Author: andre
 * 
 * Created on 12 de noviembre de 2024, 14:39
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#include "ClienteB.h"

ClienteB::ClienteB() {
    descuento = 0;
    flete = 0;
}

void ClienteB::SetFlete(double flete) {
    this->flete = flete;
}

double ClienteB::GetFlete() const {
    return flete;
}

void ClienteB::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double ClienteB::GetDescuento() const {
    return descuento;
}
void ClienteB::lee(ifstream& arch,char catego){
    char c;
    arch >> descuento >> c >> flete >> c;
    Cliente::lee(arch,catego);
}

void ClienteB::imprime(ofstream& arch, double descuento, double flete){
    Cliente::imprime(arch,descuento,flete);
}

void ClienteB::calcula(double monto){
    SetTotalPed(GetTotalPed()+monto*(1-(descuento/100))+ monto*flete/100);
    SetCantPed(GetCantPed()+1);
}


