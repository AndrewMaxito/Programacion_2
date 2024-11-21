
/* 
 * File:   Vehiculo.cpp
 * Author: andre
 * 
 * Created on 20 de noviembre de 2024, 09:05 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    cliente = 0;
    placa = nullptr;
    ped = nullptr;
}

Vehiculo::Vehiculo(const Vehiculo& orig) {
}

Vehiculo::~Vehiculo() {
    if (placa != nullptr)delete[] placa;
    eliminar();
}

void Vehiculo::eliminar() {
    NPedido *recorrido= ped;
    while (recorrido) {
        NPedido *eliminar = recorrido;
        recorrido = recorrido->sig;
        delete eliminar->codigo;
        delete eliminar;
    }
    ped = nullptr;
}
