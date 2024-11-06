
/* 
 * File:   SemiPresencial.cpp
 * Author: andre
 * 
 * Created on 5 de noviembre de 2024, 16:30
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "SemiPresencial.h"

SemiPresencial::SemiPresencial() {
    descuento = 0.0;
    total = 0.0;
}

void SemiPresencial::SetTotal(double total) {
    this->total = total;
}

double SemiPresencial::GetTotal() const {
    return total;
}

void SemiPresencial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double SemiPresencial::GetDescuento() const {
    return descuento;
}

//S,202123703,GAMARRA/TABORI/PAUL-RONAL,5,30
//P,202119153,MENDOZA/ARIAS/HENRY,4,10
//V,202318072,RIVERA/MONTERO/GLORIA-OFELIA,3,323R33-2

void SemiPresencial::leerDatos(ifstream &arch){
    Alumno::leerDatos(arch);
    arch >> descuento;
}

void SemiPresencial::actualiza(double monto){
    total = monto * GetDescuento() / 100;
    Alumno::SetTotal(monto - total);
}

void SemiPresencial::imprime(ofstream& arch){
    Alumno::imprime(arch);
    arch << right << setw(15) << "-" << setw(10) << Alumno::GetTotal() << endl;
}

