/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 11 de junio de 2024, 18:16
 */

#include <iostream>
#include <iomanip>
#include "Tesoreria.h"
using namespace std;

int main(int argc, char** argv) {
    Tesoreria Oteso;
    
    Oteso.cargarescalas();
    Oteso.cargaralumnos();
    Oteso.imprimeboleta();



    return 0;
}

