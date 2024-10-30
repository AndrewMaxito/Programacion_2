
/* 
 * File:   main.cpp
 * Author: AndrewMax
 *
 * Created on 29 de octubre de 2024, 19:05
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Almacen.h"

int main(int argc, char** argv) {
    class Almacen almacen;
    almacen.cargar_clientes();
    almacen.cargar_productos();
    almacen.cargar_pedidos();
    almacen.mostrar_datos();
    return 0;
}

