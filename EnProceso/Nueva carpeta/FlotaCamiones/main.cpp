/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 19 de octubre de 2024, 18:37
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "PilaConEnteros.h"
#include "PilaConRegistros.h"
#include "FlotaGenerica.h"

/*
 * 
 */
int main(int argc, char** argv) {
    int numCamiones;
    double pesoMaximo;
    void *flota;
    
    numCamiones = 5;
    pesoMaximo = 10;
    
    cargaCamiones(flota,numCamiones,pesoMaximo,leeNumero,calculaNumero,"numeros.txt");
    
    
    
    
    

    return 0;
}

