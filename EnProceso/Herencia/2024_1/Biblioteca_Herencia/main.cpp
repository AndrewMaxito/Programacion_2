

/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 7 de noviembre de 2024, 11:38
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "Biblioteca.h"

int main(int argc, char** argv) {
    Biblioteca biblioteca;
    
    biblioteca.cargar_libros();
    biblioteca.cargar_estantes();
    
    //biblioteca.posicionar_libros();

    return 0;
}

