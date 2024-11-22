/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 20 de noviembre de 2024, 09:37 PM
 */

#include <iostream>
#include <iomanip>
#include "Registros.h"
using namespace std;


int main(int argc, char** argv) {
    //
    Registros registroDat;
    registroDat.cargarDatos();
    registroDat.UsoTad();
    registroDat.sacarDatosTad();
    return 0;
}

