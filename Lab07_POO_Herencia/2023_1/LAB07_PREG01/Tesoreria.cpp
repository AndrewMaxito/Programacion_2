
/* 
 * File:   Tesoreria.cpp
 * Author: andre
 * 
 * Created on 27 de mayo de 2024, 18:38
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


#include "Tesoreria.h"

void Tesoreria::cargaescalas(const char* nomArch) {
    ifstream arch(nomArch, ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    int cod;
    double prec;

    //
    while (true) {
        arch >> cod;
        if (arch.eof()) break;
        arch.get();
        arch >> prec;
        // 

        lescala[cod - 1].SetCodigo(cod); //cod-1 para que se ingresen de forma ordenada
        lescala[cod - 1].SetPrecio(prec);
    }
}

void Tesoreria::cargaalumnos(const char* nomArch) {
    ifstream arch(nomArch, ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    char tipoAl, nombre[100], licencia[100], c;
    int codigo, escala, cantPre = 0, cantSemi = 0, cantVirt = 0;
    double recargo, descuento;

    while (true) {
        arch >> tipoAl;
        if (arch.eof()) break;
        arch.get();
        //
        switch (tipoAl) {
            case 'P':
                lpresencial[cantPre].leerDatos(arch);
                cantPre++;
                break;
            case 'S':
                lsemipresencial[cantSemi].leerDatos(arch);
                cantSemi++;
                break;
            case 'V':
                lvirtual[cantVirt].leerDatos(arch);
                cantVirt++;
                break;
        }
    }
    //Esto se usaria pero ya se inicializo todo en 0 asi que no es necesario creo ;v
    /*
    lpresencial[cantPre].SetCodigo(0);
    lsemipresencial[cantSemi].SetCodigo(0);
    lvirtual[cantVirt].SetCodigo(0);
     */
}

void Tesoreria::actualiza(double cred) {
    int esc;
    double precioEsc;
    //Para los registros Presenciales
    for (int i = 0; lpresencial[i].GetCodigo(); i++) {
        esc = lpresencial[i].GetEscala();
        precioEsc = lescala[esc - 1].GetPrecio();
        lpresencial[i].actualiza(cred * precioEsc);
    }

    //Para los registros Semispresenciales
    for (int i = 0; lsemipresencial[i].GetCodigo(); i++) {
        esc = lsemipresencial[i].GetEscala();
        precioEsc = lescala[esc - 1].GetPrecio();
        lsemipresencial[i].actualiza(cred * precioEsc);
    }

    //Para los registros Vittuales
    for (int i = 0; lvirtual[i].GetCodigo(); i++) {
        esc = lvirtual[i].GetEscala();
        precioEsc = lescala[esc - 1].GetPrecio();
        lvirtual[i].actualiza(cred * precioEsc);
    }
}

void Tesoreria::imprime(const char* nomArch) {
    ofstream arch(nomArch, ios::out);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }

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


