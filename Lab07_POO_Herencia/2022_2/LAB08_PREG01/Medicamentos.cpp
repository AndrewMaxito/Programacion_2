
/* 
 * File:   Medicamentos.cpp
 * Author: andre
 * 
 * Created on 28 de mayo de 2024, 12:36
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Medicamentos.h"

Medicamentos::Medicamentos() {
    codigo=0;
    nombre=nullptr;
    cantidad=0;
    precio=0.0;
    fecha=0;
}


Medicamentos::~Medicamentos() {
    if (nombre != nullptr)delete[] nombre;
}

void Medicamentos::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Medicamentos::GetFecha() const {
    return fecha;
}

void Medicamentos::SetPrecio(double precio) {
    this->precio = precio;
}

double Medicamentos::GetPrecio() const {
    return precio;
}

void Medicamentos::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Medicamentos::GetCantidad() const {
    return cantidad;
}

void Medicamentos::SetNombre(const char* cad) {
    if (nombre != nullptr) delete[] nombre;
    nombre = new char [strlen(cad)+1];
    strcpy(nombre,cad);
}

void Medicamentos::GetNombre(char *cad) const {
    if (nombre == nullptr)cad[0]=0;
    else strcpy(cad,nombre);
}

void Medicamentos::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Medicamentos::GetCodigo() const {
    return codigo;
}



void Medicamentos::cargarDatosMedicamento(int codigoMedicamneto,int cantMedi,int fecha,
        ifstream & archMedicamneto){
    int codigoMed;
    char nombreMed[100],c;
    double precioMed;
    //comienza a leer todo el archivo nuevamnete
    archMedicamneto.clear();
    archMedicamneto.seekg(0,ios::beg);
    while (true){
        archMedicamneto >> codigoMed;
        if (archMedicamneto.eof()){
            //Solo para verificar que el medicamneto esta ingresado
            cout<<"No se encontro el medicamneto "<<endl;
            exit (1);
        }
        archMedicamneto.get();
        archMedicamneto.getline(nombreMed,100,',');
        archMedicamneto >> precioMed;
        if (codigoMed == codigoMedicamneto){
//            cout<<codigoMed<<endl;
            break;
            
        }
    }
    SetCodigo(codigoMedicamneto);
    SetNombre(nombreMed);
    SetCantidad(cantMedi);
    SetPrecio(precioMed);
    SetFecha(fecha);
}

