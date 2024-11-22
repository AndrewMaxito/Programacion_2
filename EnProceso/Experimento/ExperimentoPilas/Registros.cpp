/* 
 * File:   Registros.cpp
 * Author: andre
 * 
 * Created on 21 de noviembre de 2024, 03:41 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Registros.h"

Registros::Registros() {
    cantidadDatos = 0;
}

void Registros::SetCantidadDatos(int cantidadDatos) {
    this->cantidadDatos = cantidadDatos;
}

int Registros::GetCantidadDatos() const {
    return cantidadDatos;
}

void Registros::cargarDatos() {
    ifstream arch("archExp.txt", ios::in);
    if (!arch) {
        cout << "No se pudo abrir el aerchivo de prueba" << endl;
        exit(1);
    }
    int numero;
    char tipo, c, cad[100];

    while (true) {
        datos[cantidadDatos].cargarDatoObj(arch);
        if (arch.eof())break;
        cantidadDatos++;
    }

}

void Registros::UsoTad() {
    
    for (int i = 0; i < cantidadDatos; i++) {
        pilaDatos.apilar(datos[i]);
    }
    pilaDatos.imprimir();

}

void Registros::sacarDatosTad() {
    ClDatos datoAux;
    
    datoAux = pilaDatos.desapilar();
    pilaDatos.imprimir();
}



