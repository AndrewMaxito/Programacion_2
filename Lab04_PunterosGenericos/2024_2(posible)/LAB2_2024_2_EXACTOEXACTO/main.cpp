
/* 
 * File:   main.cpp
 * Author: 51969
 *
 * Created on 30 de setiembre de 2024, 16:34
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "punterosgenericos.h"
/*
 * 
 */
int main(int argc, char** argv) {
    void* platos, *repartidores;
    leerplatos(platos);
    imprimirplatos(platos);
    leerrepartidores(repartidores);
    imprimirrepartidores(repartidores);

    cargarpedidos(repartidores,platos);
    imprimirborradorpedidos(repartidores);
    return 0;
}

