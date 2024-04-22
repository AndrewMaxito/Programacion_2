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
    leerUsurarios(usuarios);
    imprimirUsuarios(usuarios);
    return 0;
}

