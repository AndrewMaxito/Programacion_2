

/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 5 de noviembre de 2024, 16:16
 */

#include <iostream>
#include <iomanip>
#include <fstream>

#include "Tesoreria.h"

using namespace std;

int main(int argc, char** argv) {
    class Tesoreria caja;
    caja.cargaEscalas();
    caja.cargaAlumnos();
    caja.actualiza(20);
    caja.imprime("Reporte1.txt");
    return 0;
}

