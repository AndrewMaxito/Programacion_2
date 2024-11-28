

/* 
 * File:   NVehiculo.cpp
 * Author: andre
 * 
 * Created on 27 de noviembre de 2024, 09:24 PM
 */
#include <iostream>
#include <iomanip>
#include "NVehiculo.h"
#include "Furgon.h"
#include "Camion.h"
using namespace std;
NVehiculo::NVehiculo() {
    unidad = nullptr;
}

NVehiculo::NVehiculo(const NVehiculo& orig) {
    unidad = orig.unidad;
}

NVehiculo::~NVehiculo() {
    //if (unidad != nullptr)delete unidad;
}

void NVehiculo::cargaDatos(ifstream& arch, char tipo) {
    switch (tipo){
        case 'F':
            unidad = new Furgon;
            break;
        case 'C':
            unidad = new Camion;
            break; 
    }
    unidad->lee(arch); 
}


/*
        F,79464412,K0D-676,300,1,3
        F,16552775,S7E-946,300,2,3
    //Tipo de Vehículo, Cliente, Placa, Máxima carga, Filas/Ejes, Puertas/Llantas.
     */

void operator >>(ifstream &arch,NVehiculo &contenedor){
    char tipo;
    arch >> tipo;
    if (arch.eof())return ;
    arch.get();//coma
    contenedor.cargaDatos(arch,tipo); 
}

void NVehiculo::ImprimirDatos(ofstream& arch)const {
    unidad->imprime(arch);
}

bool NVehiculo::operator<(const NVehiculo& right) const {
    return right.unidad->GetCliente() > unidad->GetCliente(); // Reuse greater than operator
}

int NVehiculo::metodoObtenerDni() const {
    return unidad->GetCliente();
}

void NVehiculo::agregarPedido(NPedido& ped) {
    unidad->cargaDeposito(ped);
}

