

/* 
 * File:   Conreceta.cpp
 * Author: andre
 * 
 * Created on 7 de Nov de 2024, 16:33
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Conreceta.h"

Conreceta::Conreceta() {
    codmed = 0;
    especialidad = nullptr;
}

Conreceta::~Conreceta() {
    if (especialidad != nullptr)delete[] especialidad;
}

void Conreceta::setEspecialidad(const char* cad) {
    if (especialidad != nullptr)delete[] especialidad;
    especialidad = new char [strlen(cad) + 1];
    strcpy(especialidad, cad);
}

void Conreceta::getEspecialidad(char *cad) const {
    if (especialidad == nullptr) cad[0] = 0;
    else strcpy(cad, especialidad);
}

void Conreceta::setCodmed(int codmed) {
    this->codmed = codmed;
}

int Conreceta::getCodmed() const {
    return codmed;
}



//

void Conreceta::cargarDatosConRec(int codigoMed, char *especiali, int codigoMedicamneto,
        int cantMedi, int fecha, ifstream & archMedica) {
    Medicamentos::cargarDatosMedicamento(codigoMedicamneto,cantMedi,fecha,archMedica);
    codmed = codigoMed;
    setEspecialidad(especiali);
}

