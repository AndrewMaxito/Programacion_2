
/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 31 de octubre de 2024, 00:59
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "Biblioteca.h"
/*
 * 
 */
int main(int argc, char** argv) {
    class Biblioteca biblioteca;
    
    biblioteca.cargar_libros();
    biblioteca.cargar_estantes();
    
    biblioteca.posicionar_libros();
    biblioteca.mostrar_datos();
    
    

    return 0;
}

