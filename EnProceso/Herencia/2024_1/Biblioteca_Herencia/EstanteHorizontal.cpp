

/* 
 * File:   EstanteHorizontal.cpp
 * Author: andre
 * 
 * Created on 7 de noviembre de 2024, 12:08
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "EstanteHorizontal.h"

EstanteHorizontal::EstanteHorizontal() {
    cantidad_novelas = 0;
}

void EstanteHorizontal::SetCantidad_novelas(int cantidad_novelas) {
    this->cantidad_novelas = cantidad_novelas;
}

int EstanteHorizontal::GetCantidad_novelas() const {
    return cantidad_novelas;
}

void EstanteHorizontal::leerDatosEstaHori(ifstream &arch){
    Estantes::leerDatosEstante(arch);
}



