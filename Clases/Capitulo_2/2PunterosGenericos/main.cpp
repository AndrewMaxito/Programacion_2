/* 
 * Proyecto: ArregloDePunterosVoid
 * Archivo: main.cpp
 * Autor: J. Miguel Guanira Erazo (Juan Miguel)
 * 
 * Creado el 16 de mayo de 2020, 12:15 PM
 * 
 * Datos : 93526371,Juan Loprez Quispe,4675.25
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "FuncionesPunterosVoid.h"

int main(int argc, char** argv) {
    void *personas;
    int numPer;

    leeDatos(personas, numPer);
    ordenar(personas, 0, numPer - 1);
    imprimeDatos(personas, numPer);

    return 0;
}



