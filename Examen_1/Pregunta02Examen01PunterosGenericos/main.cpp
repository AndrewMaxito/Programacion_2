/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 13 de mayo de 2024, 18:39
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "Pregunta02Examen01PunterosGenericos.h"

int main(int argc, char** argv) {
    void *productos;
    cargarProductos(productos,"Productos.csv");
    pruebaDecargarDeProductos(productos);



    return 0;
}

