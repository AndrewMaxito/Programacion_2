
/* 
 * File:   Biblioteca.cpp
 * Author: andre
 * 
 * Created on 30 de octubre de 2024, 11:50
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Biblioteca.h"

Biblioteca::Biblioteca() {
    cantidad_estantes = 0;
    cantidad_libros = 0;
}

Biblioteca::~Biblioteca() {
}

void Biblioteca::SetCantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

int Biblioteca::GetCantidad_libros() const {
    return cantidad_libros;
}

void Biblioteca::SetCantidad_estantes(int cantidad_estantes) {
    this->cantidad_estantes = cantidad_estantes;
}

int Biblioteca::GetCantidad_estantes() const {
    return cantidad_estantes;
}

void Biblioteca::cargar_libros() {
    ifstream archLib("libros.csv", ios::in);
    if (!archLib.is_open()) {
        cout << "No se pudo abrir el archivo libros.csv" << endl;
        exit(1);
    }

    while (true) {
        archLib >> libros[cantidad_libros];
        if (archLib.eof())break;
        cantidad_libros++;
    }
}

void Biblioteca::cargar_estantes() {

    ifstream archEstan("estantes.csv", ios::in);
    if (!archEstan.is_open()) {
        cout << "No se pudo abrir el archivo estantes.csv" << endl;
        exit(1);
    }
    while (true) {
        archEstan >> estantes[cantidad_estantes];
        if (archEstan.eof())break;
        cantidad_estantes++;
    }
}

void Biblioteca::posicionar_libros() {
    int estanteAct = 0;
    for (int i = 0; i < cantidad_libros; i++) {
        for (int j = 0; j < cantidad_estantes; j++) {
            if ((estantes[j] += libros[i])){
                libros[i].SetColocado(true);
                break;
            } else libros[j].SetColocado(false); //aqui est mal
        }
    }
}

void Biblioteca::mostrar_datos() {

    ofstream archRep("ReporteEstantes.txt", ios::out);
    if (!archRep.is_open()) {
        cout << "error no se pudo abrir el archivo reporte" << endl;
        exit(1);
    }

    for (int i = 0; i < cantidad_estantes; i++) {
        archRep << estantes[i];
    }



}