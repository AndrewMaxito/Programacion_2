/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 18 de abril de 2024, 12:59
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "AsignacionDinamicaDeMemoriaExacta.h"

int main(int argc, char** argv) {
    char ***libros,***pedidosLibros;
    int **stock,**pedidosClientes;
    bool **pedidosAtendidos;
    
    //Pregunta 1 
    lecturaDeLibros("Libros.csv",libros,stock);
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt",libros,stock);
    
    //Pregunta 2 
    atencionDePedidos("Pedidos.txt",libros,stock,pedidosClientes,pedidosLibros,pedidosAtendidos);
    
    
    



    return 0;
}

