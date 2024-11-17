

/* 
 * File:   Novela.cpp
 * Author: andre
 * 
 * Created on 17 de noviembre de 2024, 12:37 PM
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Novela.h"

Novela::Novela() {
    autor = nullptr;
}


Novela::~Novela() {
    if (autor != nullptr)delete[] autor;
}

void Novela::SetAutor(const char* cad) {
    if (autor != nullptr)delete[]autor;
    autor = new char [strlen(cad)+1];
    strcpy(autor,cad);
}



void Novela::lee(ifstream& arch){
    Libro::lee(arch);
    char autB[100];
    arch.getline(autB,100);
    //
    SetAutor(autB);
}

void Novela::actualiza() {
    
}

void Novela::imprime(ofstream& arch) {
    Libro::imprime(arch);
    arch << "Autor:  "<<autor<<endl;
}




