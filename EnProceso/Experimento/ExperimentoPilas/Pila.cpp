
/* 
 * File:   Pila.cpp
 * Author: andre
 * 
 * Created on 20 de noviembre de 2024, 09:38 PM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Pila.h"

Pila::Pila() {
    cabeza = nullptr;
    longitud = 0;
}

Pila::Pila(const Pila& orig) {
    cout << "No deberia entrar aqui "<<endl;
}

Pila::~Pila() {
    destruir();
}

bool Pila::esPilaVacia() const {
    return cabeza == nullptr;
}

void Pila::apilar(const ClDatos& dato) {
    Nodo *nuevoNodo = new Nodo;
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
    longitud++;
}

ClDatos Pila::desapilar() {
    if (esPilaVacia()){
        cout << "La pila esta vacia, por lo tanto no se puede desapilar"<<endl;
        return ClDatos(); 
    }else{
        ClDatos elemento = cima();
        eliminarCabeza();
        return elemento;
    }
}

ClDatos Pila::cima() {
    if (esPilaVacia()){
        cout << "La pila esta vacia por lo tanto no posee cima"<<endl;
        return ClDatos();
    }
    return cabeza->dato;
}

void Pila::eliminarCabeza() {
    Nodo *nodoAEliminar = cabeza;
    if (nodoAEliminar != nullptr) {
        cabeza = cabeza->siguiente;
        delete nodoAEliminar;
        longitud--;
    }
}

void Pila::destruir() {
    Nodo *recorrido = cabeza;
    while (recorrido) {
        Nodo *nodoAEliminar = recorrido;
        recorrido = recorrido->siguiente;
        delete nodoAEliminar;
    }
    cabeza = nullptr;
    longitud = 0;
}

void Pila::imprimir() {
    if (esPilaVacia()){
        cout << "La pila esta vacia no hay nada que mostrar"<<endl;
    }else{
        Nodo *recorrido = cabeza;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";
        while (recorrido) {
            if (!estaImprimiendoLaCabeza) cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->dato.GetCodigoDato();
            recorrido = recorrido->siguiente;
        }
        cout << "]" <<endl;
    }
}


