
/* 
 * File:   Lista.cpp
 * Author: andre
 * 
 * Created on 19 de noviembre de 2024, 16:13
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Lista.h"

Lista::Lista() {
    lini = nullptr;
    lfin = nullptr;
}
Lista::~Lista() {
    // Destruir lista
    Nodo *recorridoInv = lfin;
    while (recorridoInv) {
        Nodo *eliminar = recorridoInv;
        recorridoInv = recorridoInv->ant; // Avanza al nodo anterior
        delete eliminar->ped;            // Libera la memoria del contenido
        delete eliminar;                 // Libera la memoria del nodo
    }
    lfin = nullptr; // Establece los punteros de la lista a nullptr
    lini = nullptr;
}

void Lista::insertarOrdenado(Pedido *pedido) {
    Nodo *nuevoNodo = new Nodo;
    nuevoNodo->ped = pedido;

    // Caso 1: Lista vacía
    if (esListaVacia()) {
        lini = nuevoNodo;
        lfin = nuevoNodo;
        return;
    }

    // Caso 2: Insertar al inicio
    if (pedido->GetDni() < lini->ped->GetDni() or
            (pedido->GetDni() == lini->ped->GetDni() and pedido->GetFecha() < lini->ped->GetFecha())) {
        nuevoNodo->sig = lini;
        lini->ant = nuevoNodo;
        lini = nuevoNodo;
        return;
    }

    // Caso 3: Insertar en el medio
    Nodo *recorrer = lini;
    while (recorrer) {
        if (pedido->GetDni() < recorrer->ped->GetDni() or
                (pedido->GetDni() == recorrer->ped->GetDni() and pedido->GetFecha() < recorrer->ped->GetFecha())) {
            nuevoNodo->sig = recorrer;
            nuevoNodo->ant = recorrer->ant;
            if (recorrer->ant) {
                recorrer->ant->sig = nuevoNodo;
            }
            recorrer->ant = nuevoNodo;
            return;
        }
        recorrer = recorrer->sig;
    }

    // Caso 4: Insertar al final
    lfin->sig = nuevoNodo;
    nuevoNodo->ant = lfin;
    lfin = nuevoNodo;
}
//void Lista::insertarOrdenado(Pedido *pedido) {
//    Nodo *nuevoNodo = new Nodo;
//    nuevoNodo->ped = pedido;
//    if (esListaVacia()) {
//        lini = nuevoNodo;
//        lfin = nuevoNodo;
//        return;
//    } else {
//        //inserta en el medio o final
//        Nodo *recorrer = lini;
//        while (recorrer) {
//            if (pedido->GetDni() < recorrer->ped->GetDni() or
//                    (pedido->GetDni() == recorrer->ped->GetDni() and pedido->GetFecha() < recorrer->ped->GetFecha())) {
//                // Insertar en el medio
//                nuevoNodo->sig = recorrer;
//                nuevoNodo->ant = recorrer->ant;
//                if (recorrer->ant) {
//                    recorrer->ant->sig = nuevoNodo;
//                } else lini = nuevoNodo;
//                recorrer->ant = nuevoNodo;
//                return;
//            }
//            recorrer = recorrer->sig;
//        }
//    }
//    // Caso 4: Insertar al final
//    lfin->sig = nuevoNodo;
//    nuevoNodo->ant = lfin;
//    lfin = nuevoNodo;
//}

bool Lista::esListaVacia() {
    return lini == nullptr;
}

void Lista::imprimirLista(ofstream& arch) {
    if (esListaVacia()) {
        cout << "La lista esta vacia no hay ningun dato" << endl;
        return;
    }

    Nodo *recorrido = lini;
    while (recorrido) {
        recorrido->ped->imprime(arch);
        recorrido = recorrido->sig;
    }
}

void Lista::modificarFlete(int dniPer, int fecha) {
    if (esListaVacia()) {
        cout << "La lista esta vacia no hay ningun dato" << endl;
        return;
    }

    Nodo *recorridoInv = lfin;
    while (recorridoInv) {
        if (recorridoInv->ped->GetDni() == dniPer) {
            if (recorridoInv->ped->GetFecha() < fecha) {
                recorridoInv->ped->modificarFlete();
            }
        }
        recorridoInv = recorridoInv->ant;
    }
}