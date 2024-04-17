/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 16 de abril de 2024, 13:01
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "AsignacionDinamicaDeMemoriaExacta.h"

int main(int argc, char** argv) {
    char ***productos,***codigoPedidos;
    int *stock,*fechaPedidos,***dniCantPedidos;
    double *precio;
    
    //Pregunta 1 
    lecturaDeProductos("Productos.csv",productos,stock,precio);
    PruebaDeLecturaDeProductos("ReporteDeProductos.txt",productos,stock,precio);
    
    //Pregunta 2
    lecturaDePedidos("Pedidos.csv",fechaPedidos,codigoPedidos,dniCantPedidos);
    PruebaDeLecturaDePedidos("ReporteDePedidos.txt",fechaPedidos,codigoPedidos,dniCantPedidos);
    
    



    return 0;
}

