/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 28 de marzo de 2024, 19:22
 */

#include <iostream>
#include <iomanip>
using namespace std;

#include "Estructuras.h"
#include "sobreCargaOpera.h"
#include "AperturaDeArchivos.h"
#include "funcionesAuxliares.h"

int main(int argc, char** argv) {
    struct Cliente arrClien[300];
    leerClientes(arrClien,"Clientes.csv");
//    
    struct Producto arrPro[300];
    leerProductos(arrPro,"Productos.csv");
//    
    completarClientesProductos(arrClien,arrPro,"Pedidos.csv");
//    
    elaborarReporte(arrClien,arrPro,"Reporte.txt");
//    
//    



    return 0;
}

