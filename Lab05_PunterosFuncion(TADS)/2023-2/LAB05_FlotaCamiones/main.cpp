/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 30 de abril de 2024, 14:28
 */

//#include <iostream>
//#include <iomanip>
#include "PilaConEnteros.h"
#include "PilaConRegistro.h"
#include "FlotaGenericas.h"

using namespace std;

int main(int argc, char** argv) {
    int numcamiones;
    double pesomaximo;
    void *flota;
    
    // prueba de lectura para el soporte
    numcamiones=5;
    pesomaximo =10;
    
    cargaCamiones(flota,numcamiones,pesomaximo,leenumero,calculanumero,"numeros.txt");
    qsort(flota,numcamiones,sizeof(void *),cmpnumero);
    muestraCamiones(flota,numcamiones,imprimenumero,"reportenum.txt");
    
    numcamiones =100;
    pesomaximo=400;
    cargaCamiones(flota,numcamiones,pesomaximo,leeregistro,calcularegistro,"pedidos3.csv");
    qsort(flota,numcamiones,sizeof(void *),cmpregistro);
    muestraCamiones(flota,numcamiones,imprimeregistro,"reporteregistro.txt");



    return 0;
}

