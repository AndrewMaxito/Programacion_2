

/* 
 * File:   Farmacia.cpp
 * Author: andre
 * 
 * Created on 28 de mayo de 2024, 12:43
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#define CANT_LINEAS 120

#include "Farmacia.h"

void Farmacia::cargamedico(const char*nombArch) {
    ifstream arch(nombArch, ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    int codigo, cant = 0;
    char nom[100], espc[100];


    while (true) {
        arch>>codigo;
        if (arch.eof())break;
        arch.get();
        arch.getline(nom, 100, ',');
        arch.getline(espc, 100);

        //
        lmedico[cant].SetCodigo(codigo);
        lmedico[cant].SetNombre(nom);
        lmedico[cant].SetEspecialidad(espc);
        cant++;
    }
}

void Farmacia::leerecetas(const char*nombArchRec, const char*nombArchMedica) {
    ifstream archRec(nombArchRec, ios::in);
    if (!archRec.is_open()) {
        cout << "No se pudo abrir el archivo " << nombArchRec << endl;
        exit(1);
    }
    ifstream archMedica(nombArchMedica, ios::in);
    if (!archMedica.is_open()) {
        cout << "No se pudo abrir el archivo " << nombArchMedica << endl;
        exit(1);
    }
    int dni, codigoMed, codigoMedicamneto, dd, mm, aaaa, fecha, cantMedi;
    char nombreCliente[100], c;
    int cantConR = 0, cantSinR = 0;


    while (true) {
        archRec >> dd;
        if (archRec.eof()) break;
        archRec >> c >> mm >> c >> aaaa >> c >> dni >> c;
        archRec.getline(nombreCliente, 100, ',');
        archRec >> codigoMed;
        fecha = aaaa * 10000 + mm * 100 + dd;
        int posMedico = -1;
        for (int i = 0; lmedico[i].GetCodigo(); i++)
            if (lmedico[i].GetCodigo() == codigoMed) {
                posMedico = i;
                break;
            }
        char especiali[100];
        lmedico[posMedico].GetEspecialidad(especiali);


        while (archRec.get() != '\n') {
            archRec >> codigoMedicamneto >> c >> cantMedi;
            int tipoMedicamneto = (codigoMedicamneto / 10000) % 2; //primer digito del medicamneto
            switch (tipoMedicamneto) {
                case 0:
                    lconreceta[cantConR].setCodmed(codigoMed);
                    lconreceta[cantConR].setEspecialidad(especiali);
                    lconreceta[cantConR].cargarDatosMedicamento(codigoMedicamneto, cantMedi, fecha, archMedica);

                    cantConR++;
                    break;
                case 1:
                    lsinreceta[cantSinR].SetDni(dni);
                    lsinreceta[cantSinR].SetNombreS(nombreCliente);
                    lsinreceta[cantSinR].cargarDatosMedicamento(codigoMedicamneto, cantMedi, fecha, archMedica);
                    cantSinR++;
                    break;
            }
        }
    }
}

void Farmacia::imprimerecetas(const char *nombArch) {
    ofstream archRep(nombArch, ios::out);
    if (!archRep.is_open()) {
        cout << "No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }

    archRep << left << setw(10) << "Codigo" << setw(60) << "Descripcion del Med." << setw(15) <<
            "Cantidad" << setw(20) << "DNI" << "Nombre" << endl;
    imprimeLineas(archRep,'=',CANT_LINEAS);
    for (int i = 0; lsinreceta[i].GetDni(); i++) {
        char nombre[100], nomMedi[100];
        lsinreceta[i].GetNombre(nomMedi);
        lsinreceta[i].GetNombreS(nombre);
        archRep << left << setw(10) << lsinreceta[i].GetCodigo() << setw(60) << nomMedi << setw(15) <<
                lsinreceta[i].GetCantidad() << setw(20) << lsinreceta[i].GetDni() << setw(20) <<
                nombre << endl;
    }
    
    archRep<<endl<<endl;
    archRep << left << setw(10) << "Codigo" << setw(60) << "Descripcion del Med." << setw(15) <<
            "Cantidad" << setw(20) << "Codigo Med" << "Especialidad" << endl;

    imprimeLineas(archRep,'=',CANT_LINEAS);
    for (int i = 0; lconreceta[i].getCodmed(); i++) {
        char nomMedi[100], especialidad[100];
        lconreceta[i].getEspecialidad(especialidad);
        lconreceta[i].GetNombre(nomMedi);
        archRep << left << setw(10) << lconreceta[i].GetCodigo() << setw(60) << nomMedi << setw(15) <<
                lconreceta[i].GetCantidad() << setw(20) << lconreceta[i].getCodmed() << setw(20) <<
                especialidad << endl;
    }

}

void Farmacia::imprimeLineas(ofstream& arch, char car, int cant) {
    for (int i = 0; i < cant; i++) arch << car;
    arch << endl;
}

