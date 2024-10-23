

/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 9 de octubre de 2024, 19:55
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "arreglos_genericos.h"
#include "listas_genericas.h"

using namespace std;


int main(int argc, char** argv) {
    void *arreglo_heroes,*lista_heroes;
    int cantidad_total_heroes;
    llenar_arreglo_heroes(arreglo_heroes,cantidad_total_heroes,"heroes_changelog_1223.csv");
    qsort(arreglo_heroes,cantidad_total_heroes,sizeof(void *),cmp_multicriterio_void);    
    crear_lista_heroes(arreglo_heroes,lista_heroes,leer_heroe);
    imprimir_lista_heroes(lista_heroes,imprimir_registro_heroe,"Reporte_heroe_Inicial.txt");
    eliminar_lista_heroes_repetidos(lista_heroes,eliminar_registro);
    imprimir_lista_heroes(lista_heroes,imprimir_registro_heroe,"Reporte_heroe_Final.txt");
    
    

    return 0;
}

