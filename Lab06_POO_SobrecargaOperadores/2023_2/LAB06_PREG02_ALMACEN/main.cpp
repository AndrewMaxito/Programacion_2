/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 23 de mayo de 2024, 13:39
 */

#include <iostream>
#include <iomanip>
#include "Almacen.h"

using namespace std;

int main(int argc, char** argv) {
    Almacen almacen;
    almacen.cargar_clientes();
    almacen.cargar_producto();
    almacen.cargar_pedidos();
    almacen.mostrar_datos();
    return 0;
}

