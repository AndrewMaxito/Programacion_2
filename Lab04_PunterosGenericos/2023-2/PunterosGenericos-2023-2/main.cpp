/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 25 de abril de 2024, 11:56
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "PunterosGenericos.h"
#include "MuestraPunteros.h"

int main(int argc, char** argv) {
    void *productos,*clientes;
    //Pregunta 1 
    cargarProductos(productos);
    imprimeProductos(productos);
    
    cargarClientes(clientes);
    imprimeClientes(clientes);
    
    //Pregunta 2
    cargarPedidos(productos,clientes);



    return 0;
}

