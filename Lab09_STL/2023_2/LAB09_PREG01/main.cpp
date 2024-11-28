/* 
 * File:   main.cpp
 * Author: AndrewMax
 *
 * Created on 27 de noviembre de 2024, 02:09 PM
 */

#include <cstdlib>

#include "Flota.h"

using namespace std;


int main(int argc, char** argv) {
    Flota Unidades;
    Unidades.cargaFlota();
    Unidades.cargaPedidos();
    Unidades.muestraCarga();
    return 0;
}