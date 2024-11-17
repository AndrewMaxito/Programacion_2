
/* 
 * File:   Libro.cpp
 * Author: andre
 * 
 * Created on 17 de noviembre de 2024, 12:30 PM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;
#include "Libro.h"

Libro::Libro() {
    nombre = nullptr;
    paginas = 0;
    peso = 0;
}

Libro::~Libro() {
    if (nombre != nullptr)delete[] nombre;
}


double Libro::GetPeso() const {
    return peso;
}

void Libro::SetNombre(const char* cad) {
    if (nombre != nullptr)delete[]nombre;
    nombre = new char [strlen(cad)+1];
    strcpy(nombre,cad);
}


//
void Libro::lee(ifstream& arch){
    char nomB[100],c;
    arch.getline(nomB,100,',');
    //
    SetNombre(nomB);
    arch >> paginas >> c >> peso;
    arch.get();//coma
}

void Libro::imprime(ofstream& arch) {
    arch << "Titulo:  " << nombre << endl;
    arch << "Peso:  " <<peso << endl;
    arch << "Paginas:  " << paginas << endl;
}
