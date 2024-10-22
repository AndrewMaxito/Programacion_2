/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 22 de octubre de 2024, 16:41
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "PunterosMultiples.h"
#include "PunteroVoid.h"
#include "MuestraVoid.h"

#include "ColaPrioridadGenerica.h"
#include "Registros.h"

int main(int argc, char** argv) {
    char **ventaLibroCodigo, ***libro;
    int **ventasDniFechaPuntaje;
    void *ventas;
    
    void *ranking;//--------------------------

    cargaVentas(ventaLibroCodigo, ventasDniFechaPuntaje, "Ventas.csv");
    cargaLibros(libro, "Libros.csv");

    cargaVentas(libro, ventas);
    
    actulizarVentas(ventasDniFechaPuntaje, ventaLibroCodigo, ventas);
    muestraventas(ventas);
    
    cargaRanking(ranking,creaRegistro,ventas);
    
    

    return 0;
}

