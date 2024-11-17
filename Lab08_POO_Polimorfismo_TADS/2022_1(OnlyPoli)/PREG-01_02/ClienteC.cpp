
/* 
 * File:   ClienteC.cpp
 * Author: andre
 * 
 * Created on 12 de noviembre de 2024, 14:41
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "ClienteC.h"

ClienteC::ClienteC() {
    flete = 0;
}

void ClienteC::SetFlete(double flete) {
    this->flete = flete;
}

double ClienteC::GetFlete() const {
    return flete;
}

void ClienteC::lee(ifstream& arch,char catego){
    arch >> flete;
    arch.get();//coma
    Cliente::lee(arch,catego);
}

void ClienteC::imprime(ofstream& arch, double descuento, double flete){
    Cliente::imprime(arch,0,flete);
}

void ClienteC::calcula(double monto){
    SetTotalPed(GetTotalPed()+monto*flete/100);
    SetCantPed(GetCantPed()+1); 
}

