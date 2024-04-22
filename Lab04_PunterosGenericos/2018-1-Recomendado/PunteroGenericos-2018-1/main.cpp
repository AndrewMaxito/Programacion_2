/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 21 de abril de 2024, 15:00
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "PunterosGenericos.h"

int main(int argc, char** argv) {
    void *usuarios;
    //Pregunta 1
    leerUsurarios(usuarios);
    imprimirUsuarios(usuarios);

    //Pregunta 2
    leerPrestamos(usuarios);
    imprimirPrestamos(usuarios);


    return 0;
}

