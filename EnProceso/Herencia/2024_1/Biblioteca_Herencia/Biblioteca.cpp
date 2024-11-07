
/* 
 * File:   Biblioteca.cpp
 * Author: andre
 * 
 * Created on 7 de noviembre de 2024, 12:10
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Biblioteca.h"

Biblioteca::Biblioteca() {
    cantidad_estantes_verticales = 0;
    cantidad_estantes_Horizontales = 0;
    cantidad_total_enciclopedias = 0;
    cantidad_total_Novelas = 0;
}

void Biblioteca::SetCantidad_total_Novelas(int cantidad_total_Novelas) {
    this->cantidad_total_Novelas = cantidad_total_Novelas;
}

int Biblioteca::GetCantidad_total_Novelas() const {
    return cantidad_total_Novelas;
}

void Biblioteca::SetCantidad_total_enciclopedias(int cantidad_total_enciclopedias) {
    this->cantidad_total_enciclopedias = cantidad_total_enciclopedias;
}

int Biblioteca::GetCantidad_total_enciclopedias() const {
    return cantidad_total_enciclopedias;
}

void Biblioteca::SetCantidad_estantes_Horizontales(int cantidad_estantes_Horizontales) {
    this->cantidad_estantes_Horizontales = cantidad_estantes_Horizontales;
}

int Biblioteca::GetCantidad_estantes_Horizontales() const {
    return cantidad_estantes_Horizontales;
}

void Biblioteca::SetCantidad_estantes_verticales(int cantidad_estantes_verticales) {
    this->cantidad_estantes_verticales = cantidad_estantes_verticales;
}

int Biblioteca::GetCantidad_estantes_verticales() const {
    return cantidad_estantes_verticales;
}

//................

//N, ABC123, El libro de la Selva, 2, 5, Aventura, 0.75
//E, EFG123, La enciclopedia de la Vida, 2, 4, 1, 6.30

void Biblioteca::cargar_libros() {
    ifstream arch("libros2.csv", ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo libros2.csv" << endl;
        exit(1);
    }

    char tipo;
    while (true) {
        arch >> tipo;
        if (arch.eof())break;
        arch.get();
        arch >> ws;
        switch (tipo) {
            case 'N':
                novelas[cantidad_total_Novelas].leerDatosNovela(arch);
                cantidad_total_Novelas++;
                break;
            case 'E':
                enciclopedias[cantidad_total_enciclopedias].leeDatosEnciclopedia(arch);
                cantidad_total_enciclopedias++;
                break;
        }
    }
}

//H, AAA, 6, 4
//V, BBB,  4, 6

void Biblioteca::cargar_estantes() {
    ifstream arch("estantes2.csv", ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo estantes2.csv" << endl;
        exit(1);
    }

    char tipo;
    while (true) {
        arch >> tipo;
        if (arch.eof())break ;
        arch.get();
        arch >> ws;
        cout << tipo << endl;
        switch (tipo) {
            case 'H':
                estanteHorizontales[cantidad_estantes_Horizontales].leerDatosEstaHori(arch);
                cantidad_estantes_Horizontales++;
                break;
            case 'V':
                estanteVerticales[cantidad_estantes_verticales].leerDatosEstaVerti(arch);
                cantidad_estantes_verticales++;
                break;
        }
        
    }
}
////
////void Biblioteca:: posicionar_libros(){
//////    //Estantes Horizontales-> novelas
//////    int estanteActual = 0;
//////    for (int i = 0; i < cantidad_total_Novelas; i++) {
//////        
//////
//////    }
////
////    
////    
////    
////    
////    
////    
////}


