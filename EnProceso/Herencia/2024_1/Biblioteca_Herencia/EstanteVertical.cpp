
/* 
 * File:   EstanteVertical.cpp
 * Author: andre
 * 
 * Created on 7 de noviembre de 2024, 12:02
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "EstanteVertical.h"

EstanteVertical::EstanteVertical() {
    cantidad_novelas = 0;
}

void EstanteVertical::SetCantidad_novelas(int cantidad_novelas) {
    this->cantidad_novelas = cantidad_novelas;
}

int EstanteVertical::GetCantidad_novelas() const {
    return cantidad_novelas;
}

void EstanteVertical::leerDatosEstaVerti(ifstream &arch){
    Estantes::leerDatosEstante(arch);
}


