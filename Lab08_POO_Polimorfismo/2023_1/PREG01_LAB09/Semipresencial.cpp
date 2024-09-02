
/* 
 * File:   Semipresencial.cpp
 * Author: andre
 * 
 * Created on 11 de junio de 2024, 18:19
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Semipresencial.h"

Semipresencial::Semipresencial() {
    descuento=0.0;
    total = 0.0;
}

void Semipresencial::SetTotal(double total) {
    this->total = total;
}

double Semipresencial::GetTotal() const {
    return total;
}

void Semipresencial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Semipresencial::GetDescuento() const {
    return descuento;
}


void Semipresencial::leer(ifstream &arch){
    char nombre[100],c;
    int codigo,escala;
    double creditos,descuento;
    arch >> codigo;
    arch.get();
    arch.getline(nombre,100,',');
    arch >> escala >> c >> creditos >> c >> descuento;
    
    //
    Alumno::SetCodigo(codigo);
    Alumno::SetCreditos(creditos);
    Alumno::SetEscala(escala);
    Alumno::SetNombre(nombre);
    SetDescuento(descuento);
}

void Semipresencial::imprime(ofstream &arch){
    
    char nombre[100];
    Alumno::GetNombre(nombre);
    arch << left << setw(20) << Alumno::GetCodigo() << setw(40) << nombre << setw(10) << Alumno::GetEscala()
            << setw(10) << Alumno::GetCreditos() << setw(20) << " " << Alumno::GetTotal() << endl;
    
}
