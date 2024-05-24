
/* 
 * File:   Cadena.cpp
 * Author: andre
 * 
 * Created on 21 de mayo de 2024, 14:56
 */
#include <iomanip>
#include <iostream>
#include <cstring>
using namespace std;
#include "Cadena.h"



//constructor por defecto 

Cadena::Cadena() {
    inicializarCadena();
    longitud = 0;
    capacidad = 0;
}

//constructor por cadena de caracteres

Cadena::Cadena(const char * cad) {
    inicializarCadena();
    longitud = strlen(cad);
    capacidad = longitud + 1;
    setCadena(cad);
}

//Constructor con capacidad

Cadena::Cadena(int cap) {
    inicializarCadena();
    longitud = 0;
    capacidad = cap;
    cadena = new char [capacidad];
    cadena[0] = '\0'; //cadena vacia
}

//Constructor de copia

Cadena::Cadena(const Cadena& otra) { //debe pasar con const y por referencia
    inicializarCadena();
    longitud = strlen(otra.cadena);
    capacidad = longitud + 1;
    setCadena(otra.cadena);
}

//Destructor 

Cadena::~Cadena() {
    if (cadena != nullptr)
        delete[] cadena;
}
//extra

void Cadena::inicializarCadena() {
    cadena = nullptr;
}

// Metodo Set

void Cadena::setCadena(const char* cad) {
    if (cadena != nullptr) delete[] cadena;
    cadena = new char [capacidad];
    strcpy(cadena, cad);
}

//Metodos 

void Cadena::assign(const char* cad) {
    int newLongitud = strlen(cad);
    if (capacidad > newLongitud) {
        longitud = newLongitud;
        setCadena(cad);
    } else {
        capacidad = (int) ((1.3) * newLongitud + 1);
        longitud = strlen(cad);
        setCadena(cad);
    }
}

void Cadena::assign(const Cadena& otra) {
    assign(otra.cadena);
}

void Cadena::append(const char* cad) {
    int newLongitud = longitud + strlen(cad);
    if (newLongitud >= capacidad) {
        capacidad = newLongitud + 1;
        char *nuevaCadena = new char [capacidad];
        strcpy(nuevaCadena, cadena);
        strcat(nuevaCadena, cad);
        delete [] cadena;
        cadena = nuevaCadena;
    } else {
        strcat(cadena, cad);
    }
    longitud = newLongitud;
}

void Cadena::append(const Cadena& otra) {
    append(otra.cadena);
}

void Cadena::swap(Cadena& otra) {
    char* tempCadena = cadena;
    int tempLongitud = longitud;
    int tempCapacidad = capacidad;

    cadena = otra.cadena;
    longitud = otra.longitud;
    capacidad = otra.capacidad;

    otra.cadena = tempCadena;
    otra.longitud = tempLongitud;
    otra.capacidad = tempCapacidad;

}
void Cadena::print() const{
    if (cadena != nullptr) {
        cout << cadena << endl;
    }
    
}

// sobrecarga 

void Cadena::operator=(const char *cad) {
    assign(cad);
}

void Cadena::operator=(const Cadena& otra) {
    assign(otra);
}

Cadena Cadena::operator +(const Cadena& otra) const{
    Cadena nuevaCadena;
    nuevaCadena.capacidad = longitud + otra.longitud + 1;
    nuevaCadena.setCadena(cadena);
    nuevaCadena.longitud=strlen(nuevaCadena.cadena);
    nuevaCadena.append(otra);
    return nuevaCadena;
}



