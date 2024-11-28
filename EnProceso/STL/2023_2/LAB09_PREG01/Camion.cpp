

/* 
 * File:   Camion.cpp
 * Author: andre
 * 
 * Created on 27 de noviembre de 2024, 09:06 PM
 */

#include <iostream>
#include <iomanip>
#include "Camion.h"
using namespace std;
Camion::Camion() {
    ejes = 0;
    llantas = 0;
}

Camion::Camion(const Camion& orig) {
}

void Camion::lee(ifstream& arch) {
    Vehiculo::lee(arch);
    //
    char c;
    arch >> ejes >> c >> llantas;
}

void Camion::cargaDeposito(NPedido& ped) {
    if (GetMaxCarga() >= GetActCarga() + ped.GetPeso()) {
        int posLibre = mDeposito.size(); 
        if (posLibre >= 5)return ;
        mDeposito[posLibre] = ped;
        Vehiculo::cargaDeposito(ped);
    }
}



void Camion::imprime(ofstream& arch) const {
    Vehiculo::imprime(arch);
    arch << left << setw(15) << "#ejes: " << ejes << endl;
    arch << setw(15) << "#llantas: " << llantas << endl;
    if (mDeposito.empty()) {
        arch << "No hay pedidos para el cliente" << endl;
    } else {
        arch << "Lista de Pedidos: "<<endl;
        for (const auto &recorrido : mDeposito) {
            arch << left <<setw(2)<<' '<<setw(10)<<recorrido.first +1 ;
            recorrido.second.imprimirDatosCamion(arch);
        }
    }
}


