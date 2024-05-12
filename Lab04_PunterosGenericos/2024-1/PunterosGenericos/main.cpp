/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 10 de mayo de 2024, 15:37
 */

#include <iostream>
#include <iomanip>
#include "PunterosGenericos.h"
#include "MuestraPunteroGenerico.h"
using namespace std;

int main(int argc, char** argv) {
    void *clientes, *reserva;
    //Pregunta 1
    cargarclientes(clientes);
    //pregunta 2
    creareserva(reserva);
    
    //Pregunta 3 
    cargareservar(clientes,reserva);
    reportefinal(reserva);
    return 0;
}

