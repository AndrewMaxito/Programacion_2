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
    
    void *ranking;

    //Pregunta 1
    cargaVentas(ventaLibroCodigo, ventasDniFechaPuntaje, "Ventas.csv");
    cargaLibros(libro, "Libros.csv");
    
    //Pregunta 2
    cargaVentas(libro, ventas);
    actulizarVentas(ventasDniFechaPuntaje, ventaLibroCodigo, ventas);
    muestraventas(ventas);
    
    //Pregunta 3
    cargaRanking(ranking,creaRegistro,ventas);
    muestraRanking(ranking,imprimeRegistro,"ranking.txt",ventas);
    return 0;
}

