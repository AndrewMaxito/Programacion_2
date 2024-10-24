/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 24 de octubre de 2024, 16:48
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "funcionesRegistro.h"
#include "funcionesLista.h"


int main(int argc, char** argv) {
    void *listaPlatos;
    crearLista(listaPlatos,leerRegistro,"PlatosOfrecidos.csv");
    actualizarLista(listaPlatos,"OrdenesDeCompra.txt");
    //Aqui me quede falta implementar el ordena los datos de la lista (los dnis de cada nodo X plato)
    
    

    return 0;
}

