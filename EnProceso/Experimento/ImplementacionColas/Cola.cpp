

/* 
 * File:   Cola.cpp
 * Author: andre
 * 
 * Created on 21 de noviembre de 2024, 08:10 PM
 */
#include <iostream>
#include <iomanip>
using namespace std;
#include "Cola.h"

Cola::Cola() {
    cabeza = nullptr;
    cola = nullptr;
    longitud = 0;
}

Cola::Cola(const Cola& orig) {
    //Otro dia 
}

Cola::~Cola() {
    destruirCola();
}


bool Cola::esColaVacia(){
    return cabeza == nullptr;
}

void Cola::encolar(ClDatos& elemento) {
    Nodo *ultimoNodo = cola;
    Nodo *nuevoNodo = new Nodo;
    nuevoNodo->elemento = elemento; //aqui se activa la sobrecarga de copia
    
    if (ultimoNodo == nullptr) {
        cabeza = nuevoNodo;
    } else {
        ultimoNodo->siguiente = nuevoNodo;
    }
    cola = nuevoNodo;
    longitud++;
}

ClDatos Cola::desencolar() {
    if (esColaVacia()) {
        cout << "La cola esta vacia no hay datos para desencolar"<<endl;
        return ClDatos();
    }
    ClDatos elemento = retornaCabeza();
    eliminarCabeza();
    return elemento;
}

ClDatos Cola::retornaCabeza() {
    if (esColaVacia()) {
        cout << "No existe cabeza"<<endl;
        return ClDatos();
    }
    return cabeza->elemento;
}

void Cola::eliminarCabeza() {
    Nodo *nodoAEliminar = cabeza;
    if (nodoAEliminar == nullptr)
        cola = nullptr;
    else {
        cabeza = cabeza->siguiente;
        if (cabeza == nullptr)
            cola = nullptr;
        delete nodoAEliminar;
        longitud--;
    }
}

//En unr rato
void Cola::destruirCola() {
    Nodo *recorrido = cabeza;
    
    while (recorrido) {
        Nodo *nodoAEliminar = recorrido;
        recorrido = recorrido->siguiente;
        delete nodoAEliminar;
    }
    //
    cabeza = nullptr;
    cola = nullptr;
    longitud = 0;
}
