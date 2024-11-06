

/* 
 * File:   Tesoreria.cpp
 * Author: andre
 * 
 * Created on 5 de noviembre de 2024, 16:36
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Tesoreria.h"

Tesoreria::Tesoreria() {
}


//3,454.20

void Tesoreria::cargaEscalas() {
    ifstream arch("escalas.csv", ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo escalas.csv" << endl;
        exit(1);
    }

    int codigo;
    double precio;
    while (true) {
        arch >> codigo;
        if (arch.eof())break;
        arch.get();
        arch >> precio;
        //
        lescala[codigo-1].SetCodigo(codigo); //codigo-1 ya que coincide con el orden del arreglo
        lescala[codigo-1].SetPrecio(precio);
    }
}

//S,202123703,GAMARRA/TABORI/PAUL-RONAL,5,30
//P,202119153,MENDOZA/ARIAS/HENRY,4,10
//V,202318072,RIVERA/MONTERO/GLORIA-OFELIA,3,323R33-2

void Tesoreria::cargaAlumnos() {
    ifstream arch("Alumnos.csv", ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo Alumnos.csv" << endl;
        exit(1);
    }
    char tipo;
    int semiI = 0, preseI = 0, virI = 0;
    while (true) {
        arch >> tipo;
        if (arch.eof())break;
        arch.get();
        //
        switch (tipo) {
            case 'S':
                lsemipresencial[semiI].leerDatos(arch);
                semiI++;
                break;
            case 'P':
                lpresencial[preseI].leerDatos(arch);
                preseI++;
                break;
            case 'V':
                lvirtual[virI].leerDatos(arch);
                virI++;
                break;
        }
    }
}


void Tesoreria::actualiza(double creditos){
    int esc;
    double precioEsc;
    //Para los registros Presenciales
    for (int i = 0; lpresencial[i].GetCodigo(); i++) {
        esc = lpresencial[i].GetEscala();
        
        precioEsc = lescala[esc - 1].GetPrecio();
        lpresencial[i].actualiza(creditos*precioEsc);
    }
    //Para los registros Semispresenciales
    for (int i = 0; lsemipresencial[i].GetCodigo(); i++) {
        esc = lsemipresencial[i].GetEscala();
        precioEsc = lescala[esc - 1].GetPrecio();
        lsemipresencial[i].actualiza(creditos * precioEsc);
    }

    //Para los registros Vittuales
    for (int i = 0; lvirtual[i].GetCodigo(); i++) {
        esc = lvirtual[i].GetEscala();
        precioEsc = lescala[esc - 1].GetPrecio();
        lvirtual[i].actualiza(creditos * precioEsc);
    }
    
}


void Tesoreria::imprime(const char* nomArch) {
    ofstream arch(nomArch, ios::out);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }

    arch << fixed << setprecision(2);

    //Para los registros Presenciales
    for (int i = 0; lpresencial[i].GetCodigo(); i++) {
        lpresencial[i].imprime(arch);

    }

    //Para los registros Semispresenciales
    for (int i = 0; lsemipresencial[i].GetCodigo(); i++) {
        lsemipresencial[i].imprime(arch);

    }

    //Para los registros Vittuales
    for (int i = 0; lvirtual[i].GetCodigo(); i++) {
        lvirtual[i].imprime(arch);
    }
}








