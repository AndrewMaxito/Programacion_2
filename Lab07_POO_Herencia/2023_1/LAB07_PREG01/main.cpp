/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 27 de mayo de 2024, 18:26
 */

#include <iostream>
#include <iomanip>

#include "Tesoreria.h"

using namespace std;

int main(int argc, char** argv) {
    class Tesoreria caja;
    caja.cargaescalas("escalas.csv");
    caja.cargaalumnos("Alumnos.csv");
    caja.actualiza(20);
    caja.imprime("Reporte1.txt");
    return 0;
}

