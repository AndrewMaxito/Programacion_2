
/* 
 * File:   Vehiculo.cpp
 * Author: andre
 * 
 * Created on 27 de noviembre de 2024, 09:00 PM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Vehiculo.h"
using namespace std;
Vehiculo::Vehiculo() {
    cliente = 0;
    placa = nullptr;
    actCarga = 0;
}

Vehiculo::Vehiculo(const Vehiculo& orig) {

}

Vehiculo::~Vehiculo() {
    if (placa != nullptr)delete[]placa;
}

void Vehiculo::SetActCarga(double actCarga) {
    this->actCarga = actCarga;
}

double Vehiculo::GetActCarga() const {
    return actCarga;
}

void Vehiculo::SetMaxCarga(double maxCarga) {
    this->maxCarga = maxCarga;
}

double Vehiculo::GetMaxCarga() const {
    return maxCarga;
}

void Vehiculo::SetPlaca(const char* cad) {
    if (placa != nullptr)delete[] placa;
    placa = new char [strlen(cad)+1];
    strcpy(placa,cad);
    
}

void Vehiculo::GetPlaca(char* cad) const {
    if (placa == nullptr)cad[0]=0;
    else strcpy(cad,placa);
}

void Vehiculo::SetCliente(int cliente) {
    this->cliente = cliente;
}

int Vehiculo::GetCliente() const {
    return cliente;
}

void Vehiculo::lee(ifstream& arch) {
    char c,cad[100];
    arch >> cliente >> c;
    
    arch.getline(cad,100,',');
    SetPlaca(cad);
    arch >> maxCarga;
    arch.get();//coma
}

void Vehiculo::imprime(ofstream& arch) const {
    arch << left << setw(25)<<"Codigo del cliente "<<cliente<<endl;
    arch << setw(15)<<"Placa"<<placa<<endl;
    arch << setw(15)<<"Carga Maxima: "<<maxCarga<<endl;
    arch << setw(15)<<"Carga Actual: "<<actCarga<<endl;   
}

void Vehiculo::cargaDeposito(NPedido& ped) {
    actCarga += ped.GetPeso();
}




