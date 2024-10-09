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
#include "listas_genericas.h"
using namespace std;

int main(int argc, char** argv) {
    void *arreglo_heroes, *lista_heroes;
    int cantidad_total_heroes;

    //primer Paso
    llenar_arreglo_heroes(arreglo_heroes, cantidad_total_heroes, "heroes_changelog_1223.csv");
    
    //Segundo paso
    qsort(arreglo_heroes, cantidad_total_heroes, sizeof (void *), cmp_multicriterio_void);

    //----------------------------------------------------------
    // solo verifico que su creacion y  ordenamiento correctamente
    //     imprimirDatos(arreglo_heroes,cantidad_total_heroes);
    //------------------------------------------------------------

    //Tercer paso
    crear_lista_heroes(arreglo_heroes, lista_heroes, leer_heroe);
    //    imprimir_lista_heroes(lista_heroes, imprimir_registro_heroe);

    //Cuarto paso 

    eliminar_lista_heroes_repetidos(lista_heroes, eliminar_registro);
    imprimir_lista_heroes(lista_heroes, imprimir_registro_heroe);

    return 0;
}

