/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 8 de septiembre de 2024, 11:03 PM
 */

#include <iomanip>
#include <iostream>

using namespace std;
#include "MetodoExactoDeMemoria.h"

/*
 * 
 */
int main(int argc, char** argv) {
    char ***libros, ***pedidosLibros;
    int **stock, **pedidosClientes;
    bool **pedidosAtendidos;

    //Pregunta 1
    lecturaDeLibros("Libros.csv", libros, stock);
    pruebaDePedidos("ReporteDeLibrosInicial.txt", libros, stock);


    //Pregunta 2
    atencionDepedidos("Pedidos.txt", libros, stock, pedidosClientes, pedidosLibros,
            pedidosAtendidos);
    pruebaDePedidos("ReporteFinal.txt", libros, stock);

    //Pregunta 3
    reporteDeEntrega("ReporteDeEntregaDePedidos.txt",pedidosClientes,pedidosLibros,pedidosAtendidos);
    


    return 0;
}

