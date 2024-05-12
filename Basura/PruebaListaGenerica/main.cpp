/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 1 de mayo de 2024, 12:01
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "arreglos_genericos.h"

using namespace std;

void modificarDatos(void *&arreglo_heroes,int cantidad_total_heroes){
    void **registro = (void **)arreglo_heroes;
    void **dato = (void **)(registro[3]);
    int *codigo= (int *)(dato[0]);
}





int main(int argc, char** argv) {
    void *arreglo_heroes, *lista_heroes;
    int cantidad_total_heroes;

    //primer Paso
    llenar_arreglo_heroes(arreglo_heroes, cantidad_total_heroes, "heroes_changelog_1223.csv");
    modificarDatos(arreglo_heroes,cantidad_total_heroes);
    imprimirDatos(arreglo_heroes,cantidad_total_heroes);
  

    return 0;
}