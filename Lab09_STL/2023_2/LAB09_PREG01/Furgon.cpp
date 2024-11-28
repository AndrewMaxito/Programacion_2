
/* 
 * File:   Furgon.cpp
 * Author: andre
 * 
 * Created on 27 de noviembre de 2024, 09:19 PM
 */
#include <iomanip>
#include <iostream>
#include "Furgon.h"
using namespace std;

Furgon::Furgon() {
    filas = 0;
    puertas = 0;
}

Furgon::Furgon(const Furgon& orig) {
}

Furgon::~Furgon() {
}

void Furgon::lee(ifstream& arch) {
    Vehiculo::lee(arch);
    //
    char c;
    arch >> filas >> c >> puertas;
}

void Furgon::cargaDeposito(NPedido& ped) {
    if (GetMaxCarga() >= GetActCarga() + ped.GetPeso()) {
        pDeposito.push_front(ped);
        Vehiculo::cargaDeposito(ped);
    }
}

void Furgon::imprime(ofstream& arch) const {
    Vehiculo::imprime(arch);
    arch << left <<setw(15)<<"#filas: "<<filas<<endl;
    arch << left <<setw(15)<<"#puertas: "<<puertas<<endl;
    if (pDeposito.empty()) {
        arch << "No hay pedidos para el cliente"<<endl;
    }else{
        arch << "Lista de Pedidos: "<<endl;
        for (const auto &elemento: pDeposito) {
            arch << left << setw(2) << ' ';
            elemento.imprimirDatosCamion(arch);
        }
    }
}
