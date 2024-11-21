

/* 
 * File:   ClDatos.cpp
 * Author: andre
 * 
 * Created on 20 de noviembre de 2024, 09:42 PM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <string.h>
using namespace std;
#include "ClDatos.h"
#include "hijo1.h"
#include "hijo2.h"

ClDatos::ClDatos() {
    nombreDato = nullptr;
    objPadre = nullptr;
    codigoDato = 0;
}

ClDatos::ClDatos(const ClDatos& orig) {
    nombreDato = nullptr;
    objPadre = nullptr;
    *this = orig;
}

ClDatos::~ClDatos() {
    if (nombreDato != nullptr)delete[] nombreDato;
    /*
     * //si hago esto deberia crearle un constructor copia (=) a padre pero no es ncesario ya que paso el puntero
     * if (objPadre != nullptr)delete[] objPadre;
     */
}

void ClDatos::operator=(const ClDatos& datos) {
    char cadena[100];
    codigoDato = datos.codigoDato;
    datos.GetNombre(cadena);
    SetNombre(cadena);
    objPadre = datos.objPadre; //aqui se copia la direccion de memoria
}

void ClDatos::SetNombre(const char* cad) {
    if (nombreDato != nullptr)delete nombreDato;
    nombreDato = new char [strlen(cad)+1];
    strcpy(nombreDato,cad);
}

void ClDatos::GetNombre(char* cad) const {
    if (nombreDato == nullptr)cad[0] = 0;
    else strcpy(cad,nombreDato);
}

void ClDatos::SetCodigoDato(int codigoDato) {
    this->codigoDato = codigoDato;
}

int ClDatos::GetCodigoDato() const {
    return codigoDato;
}

void ClDatos::cargarDatoObj(ifstream& arch) {
    int codBuf;
    char tipo,c,cad[100];
    arch >> codBuf;
    if (arch.eof())return ;
    arch.get();
    codigoDato = codBuf;
    arch.getline(cad,100,',');
    SetNombre(cad);
    //
    arch >> tipo >> c;
    switch (tipo){
        case 'A':
            objPadre = new hijo1;
            break;
        case 'B':
            objPadre = new hijo2;
            break;
    }
    objPadre->leer(arch);
}

