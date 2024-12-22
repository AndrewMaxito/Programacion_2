/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 11 de abril de 2024, 10:28
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"

int main(int argc, char** argv) {
    
    char ***productos,***CodigoPedidos;
    int *stock,*fechaPedidos,***dniCantPedidos;
    double *precios;
    
    //Pregunta 1
    lecturaDeProductos("Productos.csv",productos,stock,precios);
    pruebaDeLecturaDeProductos("ReporteDeProductos.txt",productos,stock,precios);
    
    //Pregunta 2
    lecturaDePedidos("Pedidos.csv",fechaPedidos,CodigoPedidos,dniCantPedidos);
    pruebaDeLecturaDePedidos("ReporteDePedidos.txt",fechaPedidos,CodigoPedidos,dniCantPedidos);



    return 0;
}

