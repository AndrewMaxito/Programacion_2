

/* 
 * File:   Flota.cpp
 * Author: andre
 * 
 * Created on 27 de noviembre de 2024, 09:26 PM
 */

#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include "Flota.h"
#include "NPedido.h"
using namespace std;
#define CANT_LIN 80

Flota::Flota() {
}

Flota::Flota(const Flota& orig) {
}

Flota::~Flota() {
}

void Flota::cargaFlota() {
    ifstream arch("Vehiculos.csv", ios::in);
    if (!arch) {
        cout << "No se pudo abrir el archivo Vehiculos.csv" << endl;
        exit(1);
    }
    //
    /*
        F,79464412,K0D-676,300,1,3
        F,16552775,S7E-946,300,2,3
    //Tipo de Vehículo, Cliente, Placa, Máxima carga, Filas/Ejes, Puertas/Llantas.
     */
    NVehiculo aux;
    while (true) {
        arch >> aux;
        if (arch.eof())break;
        vFlota.push_back(aux); //No es becesario el contructor  copia ya que si le quiero pasar el polimorfico
    }
    sort(vFlota.begin(), vFlota.end()); //Si no tiene el tercer parametro y es un objeto debe sobrecargarse el <  
}

void Flota::muestraCarga() {
    ofstream arch("ReporteInicial", ios::out);
    if (!arch) {
        cout << "No se pudo abrir el archivo reportes" << endl;
        exit(1);
    }
    arch << fixed << setprecision(2);
    arch << left << setw(30) << ' ' << "Reporte De Flota" << endl;
    imprimiLineas(arch, CANT_LIN, '=');
    for (const auto &vehiculo : vFlota) {
        vehiculo.ImprimirDatos(arch);
        arch << endl;
    }
}

void Flota::imprimiLineas(ofstream& arch, int cant, char car) {
    for (int i = 0; i < cant; i++) arch << car;
    arch << endl;
}

void Flota::cargaPedidos() {
    ifstream arch("Pedidos3.csv", ios::in);
    if (!arch) {
        cout << "No se pudo abrir el archivo Pedidos3.csv" << endl;
        exit(1);
    }
    int Idcliente;
    NPedido aux;
    while (true) {
        arch >> Idcliente;
        if (arch.eof())break;
        arch.get();
        aux.leerDatosVehiculo(arch);
        int pos = buscarVehiculo(Idcliente);
        if (pos != -1) {
            vFlota[pos].agregarPedido(aux);
        }
    }
}

int Flota::buscarVehiculo(int Idcliente) {
    for (int i = 0; i < vFlota.size(); i++) {
        if (vFlota[i].metodoObtenerDni() == Idcliente) return i;
    }
    cout << "No se encontro el DNI: " << Idcliente << endl;
    return -1;
}



