/* 
 * File:   main.cpp
 * Author: Max Bardales 20192406
 *
 * Created on 13 de mayo de 2024, 16:49
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "Pregunta01Examen01PunterosMultiples.h"

int main(int argc, char** argv) {
    char **codigoProducto;
    int **fechaClienteCantidad;
    cargaPedidos(fechaClienteCantidad,codigoProducto,"Pedidos.csv");
    pruebaCargaDePedidos(fechaClienteCantidad,codigoProducto,"PruevaPedidos.txt");



    return 0;
}

