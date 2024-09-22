

/* 
 * File:   main.cpp
 * Author: Andrew Max
 *
 * Created on 21 de setiembre de 2024, 23:25
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "PunterosGenericos.h"


int main(int argc, char** argv) {
    void *productos,*clientes;
    
    //Pregunta 1
    cargarProductos(productos);
    cargarClientes(clientes);
    
    
    //Pregunta 2
    cargaPedidos(productos,clientes);

    return 0;
}

