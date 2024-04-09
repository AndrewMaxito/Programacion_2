/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 7 de abril de 2024, 16:59
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "funcionesAux.h"

int main(int argc, char** argv) {
    int **numeros, numDatos; //aqui defino en la pila mi dm del puntero

    leerDatos(numeros, numDatos, "Archivouwu.txt");
    ordenar(numeros,0,numDatos-1);




    return 0;
}

