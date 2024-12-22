/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 28 de abril de 2024, 12:08
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "MetodoExactoDeMemoria.h"

int main(int argc, char** argv) {
    char ***libros, ***pedidosLibros;
    int **stock, **pedidosClientes;
    bool **pedidosAtendidos;

    //Pregunta 1 
    lecturaDePedidos("Libros.csv", libros, stock);
    pruebaDeLecturaDePedidos("ReporteDeLibrosInicial.txt", libros, stock);

    //Pregunta 2
    atencionDePedidos("Pedidos.txt", libros, stock, pedidosClientes, pedidosLibros, pedidosAtendidos);
    pruebaDeLecturaDePedidos("ReporteDeLibrosFinal.txt", libros, stock);
    
    //Pregunta 3 
    
    reporteDeEntrega("ReporteDeEntregaDePedidos.txt",pedidosClientes,pedidosLibros,pedidosAtendidos);
    
    




    return 0;
}

