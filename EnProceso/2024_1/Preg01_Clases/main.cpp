
/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 30 de octubre de 2024, 11:20
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "Libro.h"
#include "Estante.h"

int main(int argc, char** argv) {
    ifstream archLib("libros.csv",ios::in);
    if (!archLib.is_open()){
        cout << "No se pudo abrir el archivo libros.csv"<<endl;
        exit(1);
    }
    ifstream archEstan("estantes.csv",ios::in);
    if (!archEstan.is_open()){
        cout << "No se pudo abrir el archivo estantes.csv"<<endl;
        exit(1);
    }
    
    //Lectura
    class Libro libros[100];
    archLib >> libros[0];
    archLib >> libros[1];
    archLib >> libros[2];
    
    class Estante estantes[100];
    archEstan >> estantes[0];
    archEstan >> estantes[1];
    
    //Agregacion
    estantes[0] += libros[0];
    
    ofstream archRep("reportePrueba.txt",ios::out);
    if (!archRep.is_open()) {
        cout<< "error no se pudo abrir el archivo reporte"<<endl;
        exit(1);
    }
    archRep << libros[0];
    archRep << estantes[0];
    return 0;
}

