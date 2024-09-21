
/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 19 de setiembre de 2024, 14:31
 */

#include <iomanip>
#include <iostream>

using namespace std;
#include "MetodoExactoDeMemoria.h"

int main(int argc, char** argv) {
    char ***libros, ***pedidosLibros;
    int **stock, **pedidosClientes;
    bool **pedidosAtendidos;
    //Pregunta 1
    lecturaDePedidos("Libros.csv", libros, stock);
    pruebaDeLecturaDeLecturaDeLibros("ReporteDeLibrosInicial.txt", libros, stock);
    //Pregunta 2
    atencionDePedidos("Pedidos.txt", libros, stock, pedidosClientes, pedidosLibros,
            pedidosAtendidos);
    pruebaDeLecturaDeLecturaDeLibros("ReporteDeLibrosFinal.txt", libros, stock);

    //Pregunta 3
    ordena PedidosClientes(pedidosClientes);

    //Pregunta 4
    reporteDeEntregaDePedidos("REporteDeEntregaDePedidos.txt", pedidosClientes,
            pedidosLibros, pedidosAtendidos);
    return 0;
}

