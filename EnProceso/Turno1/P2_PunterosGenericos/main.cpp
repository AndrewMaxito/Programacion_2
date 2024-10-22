
/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 21 de octubre de 2024, 22:23
 */

#include <iostream>
#include <iomanip>

using namespace std;

#include "PunteroVoid.h"
#include "MuestraVoid.h"
#include "PunterosMultiples.h"
#include "AperturaDeArchivos.h"

int main(int argc, char** argv) {
    char **ventaLibroCodigo,***libro;
    int **ventasDniFechaPuntaje;
    void *ventas;
    
    cargaVentas(ventaLibroCodigo,ventasDniFechaPuntaje,"Ventas.csv");
    cargaLibros (libro,"Libros.csv");
    
    cargaVentas(libro,ventas);
    actulizarVentas(ventasDniFechaPuntaje,ventaLibroCodigo,ventas);
    muestraventas(ventas);

    return 0;
}

