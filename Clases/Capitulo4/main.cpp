/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 21 de mayo de 2024, 14:52
 */

#include <iostream>
#include <iomanip>
#include "Cadena.h"
using namespace std;

int main(int argc, char** argv) {
    // Pruebas de inicialización
    Cadena cad1("Hola");
    Cadena cad2("Mundo");

    // Imprimir cadenas iniciales
    cout << "Cadena 1: ";
    cad1.print();
    cout << "Cadena 2: ";
    cad2.print();

    // Prueba del operador +
    Cadena cad3 = cad1 + cad2;
    cout << "Cadena 3 (cad1 + cad2): ";
    cad3.print();

    // Prueba del método append
    cad1.append(" a todos");
    cout << "Cadena 1 después de append: ";
    cad1.print();

    // Prueba del operador =
    Cadena cad4;
    cad4 = cad1;
    cout << "Cadena 4 (después de cad4 = cad1): ";
    cad4.print();

    // Prueba del método assign con const char*
    cad4.assign("Nuevo contenido");
    cout << "Cadena 4 después de assign(\"Nuevo contenido\"): ";
    cad4.print();

    // Prueba del método assign con otro objeto Cadena
    cad4.assign(cad2);
    cout << "Cadena 4 después de assign(cad2): ";
    cad4.print();



    return 0;
}

