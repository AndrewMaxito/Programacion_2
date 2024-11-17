

/* 
 * File:   Estante.cpp
 * Author: andre
 * 
 * Created on 17 de noviembre de 2024, 01:20 PM
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Estante.h"
#define CANT_LIN 80
Estante::Estante() {
    id = 0;
    capacidad = 0;
}

void Estante::SetCapacidad(double capacidad) {
    this->capacidad = capacidad;
}

double Estante::GetCapacidad() const {
    return capacidad;
}

void Estante::SetId(int id) {
    this->id = id;
}

int Estante::GetId() const {
    return id;
}

void Estante::SetClase(char clase) {
    this->clase = clase;
}



//
double Estante::GetPesoDisponible() const{
    return capacidad - Llibros.GetPeso();
}

void Estante::agregarLibro(Libro* libroLeido) {
    Llibros.inserta(libroLeido);
}

void Estante::verificarVigencia() {
    Llibros.analizarVigenciaLibros();
}

void Estante::imprimirDatosEstante(ofstream& arch) {
    arch << "Id:  "<<id<<endl;
    arch << "Tipo:  ";
    if (clase == 'H') arch << "Horizontal"<<endl;
    else arch << "Vertical"<<endl;
    arch << "Capacidad:  "<<capacidad<<endl;
    arch << "Libros Contenidos: "<<endl;
    imprimirLineas(arch,CANT_LIN,'-');
    Llibros.mostrarLista(arch);
    imprimirLineas(arch,CANT_LIN,'-');
    
}

void Estante::imprimirLineas(ofstream& arch, int cant, char car) {
    for (int i = 0; i < cant; i++) arch << car;
    arch << endl;
}


