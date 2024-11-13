

/* 
 * File:   Cliente.cpp
 * Author: andre
 * 
 * Created on 12 de noviembre de 2024, 14:11
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#include "Cliente.h"

Cliente::Cliente() {
    dni = 0;
    nombre = nullptr;
    cantPed = 0;
    totalPed = 0;
}

Cliente::Cliente(const Cliente& orig) {

}

Cliente::~Cliente() {
    if (nombre != nullptr)delete[] nombre;
}

void Cliente::SetTotalPed(double totalPed) {
    this->totalPed = totalPed;
}

double Cliente::GetTotalPed() const {
    return totalPed;
}

void Cliente::SetCantPed(int cantPed) {
    this->cantPed = cantPed;
}

int Cliente::GetCantPed() const {
    return cantPed;
}

void Cliente::SetNombre(const char* cad) {
    if (nombre != nullptr)delete[]nombre;
    nombre = new char [strlen(cad) + 1];
    strcpy(nombre, cad);
}

void Cliente::GetNombre(char *cad) const {
    if (nombre == nullptr)cad[0] = 0;
    else strcpy(cad, nombre);
}

void Cliente::SetCategoria(char categoria) {
    this->categoria = categoria;
}

char Cliente::GetCategoria() const {
    return categoria;
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

void Cliente::lee(ifstream& arch, char catego) {
    char c, nombreDat[100];
    arch >> dni >> c;
    arch.getline(nombreDat, 100);
    SetNombre(nombreDat);
    categoria = catego;
}

void Cliente::imprime(ofstream &arch, double descuento, double flete) {
    char cadNom[100];
    GetNombre(cadNom);
    arch << left << setw(15) << dni << cadNom << endl;
    if (descuento > 0)
        arch << "Descuento: " << descuento << endl;
    if (flete > 0)
        arch << "Flete: " << flete << endl;
    arch << "Total: " << totalPed << endl;
    arch << "Cantidad de Pedidos: " << cantPed << endl << endl;
}