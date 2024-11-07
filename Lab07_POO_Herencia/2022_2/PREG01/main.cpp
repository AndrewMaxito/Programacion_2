/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 7 de Nov de 2024, 16:33
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "Farmacia.h"

int main(int argc, char** argv) {
    Farmacia ofarma;
    
    ofarma.cargamedico("medicos.csv");
    ofarma.leerecetas("recetas.csv","medicamentos.csv");
    ofarma.imprimerecetas("Reporte1.txt");
    return 0;
}

