/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 10 de septiembre de 2024, 10:26 PM
 */

#include <iomanip>
#include <iostream>

using namespace std;
#include "funiconesaux.h"

/*
 * 
 */
int main(int argc, char** argv) {
    int **datos;
    cargarDatos(datos);
//    imprimirDatos(datos);
    
    modificarDatos(datos);
     imprimirDatos(datos);

    return 0;
}

