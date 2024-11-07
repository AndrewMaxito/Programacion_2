
/* 
 * File:   Sinreceta.cpp
 * Author: andre
 * 
 * Created on 7 de Nov de 2024, 16:33
 */

#include <cstring>

#include "Sinreceta.h"

Sinreceta::Sinreceta() {
    dni=0;
    nombre=nullptr;
}


Sinreceta::~Sinreceta() {
    if (nombre != nullptr)delete[]nombre;
}

void Sinreceta::SetNombreS(const char* cad) {
    if (nombre != nullptr)delete[]nombre;
    nombre= new char [strlen(cad)+1];
    strcpy(nombre,cad);
}

void Sinreceta::GetNombreS(char *cad) const {
    if (nombre == nullptr) cad[0]=0;
    else strcpy(cad,nombre);
}

void Sinreceta::SetDni(int dni) {
    this->dni = dni;
}

int Sinreceta::GetDni() const {
    return dni;
}

void Sinreceta::cargarDatosSinRec(int buDni,char* nombreCliente, int codigoMedicamneto, 
        int cantMedi,int  fecha,ifstream &archMedica){
    Medicamentos::cargarDatosMedicamento(codigoMedicamneto,cantMedi,fecha,archMedica);
    dni = buDni;
    SetNombreS(nombreCliente);
}
