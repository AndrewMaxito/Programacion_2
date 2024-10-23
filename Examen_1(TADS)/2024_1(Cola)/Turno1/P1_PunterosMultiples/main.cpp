/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 21 de octubre de 2024, 20:42
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "PunterosMultiples.h"

/*
 * 
 */



int main(int argc, char** argv) {
    char **ventaLibroCodigo,***libro;
    int **ventasDniFechaPuntaje;
    
    cargaVentas(ventaLibroCodigo,ventasDniFechaPuntaje,"Ventas.csv");
    pruebaDeCargaDeVentas(ventaLibroCodigo,ventasDniFechaPuntaje,"PruebaVentas.txt");
    cargaLibros (libro,"Libros.csv");
    pruebaDeCargaDeLibros(libro,"PruebaLibros.txt");
    
    

    return 0;
}

