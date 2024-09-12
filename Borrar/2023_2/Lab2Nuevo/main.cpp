
/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 11 de septiembre de 2024, 05:54 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "AsignacionDinamicaMemoriaExaccta.h"

int main(int argc, char** argv) {
    char ***productos, ***codigoPedidos;
    int *stock, *fechaPedidos, ***dniCanPedidos;
    double *precios;

    //Pregunta 1
    lecturaDeProductos("Productos.csv", productos, stock, precios);
    pruebaDeLecturaDeProductos("ReporteDePedidos.txt", productos, stock, precios);

    //Pregunta 2
    lecturaDePedidos("Pedidos.csv", fechaPedidos, codigoPedidos, dniCanPedidos);
    pruebaDeLecturaDePedidos("ReporteDePedidos.txt", fechaPedidos, codigoPedidos,
            dniCanPedidos);

    //Pregunta 3
    reporteDeEnvioDePedidos("ReporteDeEnvioDePedidos.txt", productos, stock,
            precios, fechaPedidos, codigoPedidos, dniCanPedidos);


    return 0;
}

