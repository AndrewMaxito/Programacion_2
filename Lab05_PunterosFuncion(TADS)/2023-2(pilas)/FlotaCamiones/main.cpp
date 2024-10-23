/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 19 de octubre de 2024, 18:37
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>

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
    qsort(flota,numCamiones,sizeof(void *),cmpNumero);
    muestraCamiones(flota,numCamiones,imprimeNumero,"ReporteNum.txt");
    
    numCamiones = 100;
    pesoMaximo=400;
    
    cargaCamiones(flota,numCamiones,pesoMaximo,leeRegistro,calculaRegistro,"Pedidos3.csv");
    qsort(flota,numCamiones,sizeof(void *),cmpRegistro);
    muestraCamiones(flota,numCamiones,imprimeRegistro,"ReporteRegistro.txt");
    
    
    
    
    

    return 0;
}

