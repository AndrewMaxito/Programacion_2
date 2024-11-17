

/* 
 * File:   main.cpp
 * Author: AndrewMax
 *
 * Created on 17 de noviembre de 2024, 12:28 PM
 */

#include <iostream>

#include "Biblioteca.h"

using namespace std;


int main(int argc, char** argv) {
    Biblioteca bli;
    
    bli.carga();
    bli.llena();
    bli.baja();
    bli.muestra();
    return 0;
}

