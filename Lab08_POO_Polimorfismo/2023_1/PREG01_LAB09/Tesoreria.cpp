

/* 
 * File:   Tesoreria.cpp
 * Author: andre
 * 
 * Created on 11 de junio de 2024, 18:20
 */

#include <iostream>

#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Tesoreria.h"
#include "Boleta.h"

void Tesoreria::cargarescalas() {
    ifstream arch("escalas.csv", ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo escalas.csv" << endl;
        exit(1);
    }
    int cod;
    double precio;
    char c;

    while (true) {
        arch >> cod;
        if (arch.eof()) break;
        arch.get();
        arch >> c >> precio;
        lescala[cod - 1].SetPrecio(precio);
        lescala[cod - 1].SetCodigo(cod);
    }
}

void Tesoreria::cargaralumnos() {
    ifstream arch("alumnos.csv", ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo alumnos.csv" << endl;
        exit(1);
    }
    int numalumnos = 0;
    
    while (true) {
        arch >> lboleta[numalumnos];
        if (arch.eof())break;
        numalumnos++;
    }
}

void Tesoreria::imprimeboleta() {
    ofstream arch("Reporte.txt",ios :: out);
    if(not arch.is_open()){
        cout << "ERROR: No se puede abrir el archivo Reporte.txt" << endl;
        exit(1);
    }
    //
    for(int i=0;lboleta[i].existe();i++){
        lboleta[i].mostrar(arch);
    }



}