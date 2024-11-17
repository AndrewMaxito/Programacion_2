

/* 
 * File:   Procesa.cpp
 * Author: andre
 * 
 * Created on 12 de noviembre de 2024, 14:48
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Procesa.h"
#define CANT_LINEAS 90

void Procesa::carga() {
    ifstream archPedi("pedidos4.csv", ios::in);
    if (!archPedi) {
        cout << "No se pudo abrir el archivo pedidos4.csv " << endl;
        exit(1);
    }

    ifstream archCli("clientes3.csv", ios::in);
    if (!archCli) {
        cout << "No se pudo abrir el archivo clientes3.csv " << endl;
        exit(1);
    }
    //Para Pedidos
    int cantidadPed = 0;
    while (archPedi >> lPedidos[cantidadPed]) cantidadPed++;
    //Para Deudores
    int cantidadCli = 0;
    while (archCli >> lDeudor[cantidadCli]) cantidadCli++;
}

void Procesa::muestra() {
    ofstream archRep("Reporte1.txt", ios::out);
    if (!archRep) {
        cout << "No se pudo abrir el archivo Reporte1.txt " << endl;
        exit(1);
    }
    archRep << fixed << setprecision(2);
    archRep << right << setw(40) << "REPORTE DE DEUDAS" << endl;
    imprimirLineas(archRep, CANT_LINEAS, '=');
    
    for (int i = 0; lDeudor[i].existe(); i++) {
        lDeudor[i].muestraDatosDeudor(archRep);
        imprimirLineas(archRep,70,'.');
    }
}

void Procesa::imprimirLineas(ofstream &archRep, int cant, char car) {
    for (int i = 0; i < cant; i++) archRep << car;
    archRep << endl;
}

void Procesa::actualiza(){
    
    for(int i=0;lDeudor[i].existe();i++)
        for(int j=0;lPedidos[j].GetCodigo();j++)
            if(lPedidos[j].GetDni()==lDeudor[i].getCodDni())
                lDeudor[i].actualizadeudor(lPedidos[j].GetTotal());
    
}

