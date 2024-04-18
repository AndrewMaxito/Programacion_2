/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 18 de abril de 2024, 09:22
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {
    int *datos;
    
    leerDatosPorIncrementos(datos, "datos.txt");
    ordenar(datos);
    imprimirDatos(datos);

    return 0;
}