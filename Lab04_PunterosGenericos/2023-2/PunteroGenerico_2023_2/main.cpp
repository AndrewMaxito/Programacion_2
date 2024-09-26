

/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 26 de setiembre de 2024, 15:09
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "PunterosGenericos.h"
#include "MuestraPunteros.h"

int main(int argc, char** argv) {
    void *productos, *cliente;
    //Pregunta 1
    cargaProducto(productos);
    //    imprimeproductos(productos);
    cargaClientes(cliente);
    //    imprimeclientes(cliente);
    //Pregunta 2
    cargarPedidos(productos, cliente);
    //    imprimerepfinal(cliente);
    //Pregunta 3
    imprimeReporte(cliente);
    return 0;
}

