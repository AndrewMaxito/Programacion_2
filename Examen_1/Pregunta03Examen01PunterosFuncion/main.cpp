/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 13 de mayo de 2024, 20:35
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Pregunta01Examen01PunterosMultiples.h"
#include "Pregunta02Examen01PunterosGenericos.h"


#include "ColaConEnteros.h"
#include "ColaGenerica.h"

int main(int argc, char** argv) {
    char **codigoProducto;
    int **fechaClienteCantidad;
    void *productos;

    void *cola;
//    cargarPedidos(fechaClienteCantidad, codigoProducto, "Pedidos.csv");
//    pruebaDeCargaDePedidos(fechaClienteCantidad, codigoProducto, "PruevaPedidos.txt");
//
//
//
//    cargarProductos(productos, "Productos.csv");
//    pruebaDecargarDeProductos(productos);
    
    cargaEnteros(cola,leenumero,"numeros.txt");
    mostrarEneteros(cola,imprimenumero,"Reporte.txt");




    return 0;
}

