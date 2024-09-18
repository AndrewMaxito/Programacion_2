
/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 18 de septiembre de 2024, 10:57 AM
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "MetodoExactoDeMemoria.h"
/*
 * 
 */
int main(int argc, char** argv) {
    char ***libros,***pedidosLibros;
    int **stock,**pedidosClientes;
    bool **pedidosAtendidos;
    lecturaDeLibros("Libros.csv",libros,stock);
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt",libros,stock);
    
    
    atencionDePedidos("Pedidos.txt",libros,stock,pedidosClientes,
            pedidosLibros,pedidosAtendidos);
        pruebaDeLecturaDeLibros("ReporteDeLibrosFinal.txt",libros,stock);


    return 0;
}

