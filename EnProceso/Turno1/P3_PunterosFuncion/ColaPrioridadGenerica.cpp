/* 
 * File:   ColaPrioridadGenerica.cpp
 * Author: andre
 * 
 * Created on 22 de octubre de 2024, 16:58
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "ColaPrioridadGenerica.h"

enum NODOESPCOL {
    CABEZA, PRI3, PRI2, PRI1
};

enum NODO {
    DATO, SIG
};

void cargaRanking(void *&ranking, void *(*creaRegistro)(void *), void *ventas) {
    //Crea no espcial (direccicon de la cola)
    ranking = generarCola();

    void **regVentas = (void **) (ventas);
    void *registro;
    for (int i = 0; regVentas[i]; i++) {
        registro = creaRegistro(regVentas[i]);
        void **datosVenta = (void **) (regVentas[i]);
        int *numRanking = (int *) (datosVenta[7]);
        encola(ranking, registro, *numRanking);
    }






}

void *generarCola() {
    void **nodoEsp = new void *[4] {
    };
    return nodoEsp;
}

void encola(void *cola, void *registro, int rank) {
    void **nuevoNodo = new void *[2] {
    };
    void **nodoEsp = (void **) cola;
    nuevoNodo[DATO] = registro;

    if (colaVacia(cola)) {//Es cola vacia 
        nodoEsp[CABEZA] = nuevoNodo;

        switch (rank) {
            case 3:
                nodoEsp[PRI3] = nuevoNodo;
                break;
            case 2:
                nodoEsp[PRI2] = nuevoNodo;
                break;
            case 1:
                nodoEsp[PRI1] = nuevoNodo;
                break;
        }
    } else {
        switch (rank) {
            case 3:
                if (nodoEsp[PRI3] == nullptr) {
                    nodoEsp[PRI3] = nuevoNodo;
                    nuevoNodo[SIG] = nodoEsp[CABEZA];
                    nodoEsp[CABEZA] = nuevoNodo;
                } else {
                    void **nodo = (void **) (nodoEsp[PRI3]);
                    nuevoNodo[SIG] = nodo[SIG];
                    nodo[SIG] = nuevoNodo;
                }
                break;
            case 2:
                if (nodoEsp[PRI2] == nullptr) {
                    nodoEsp[PRI2] = nuevoNodo;
                    if (nodoEsp[PRI3] == nullptr) {
                        nuevoNodo[SIG] = nodoEsp[CABEZA];
                        nodoEsp[CABEZA] = nuevoNodo;
                    } else {
                        void **nodo = (void **) (nodoEsp[PRI3]);
                        nuevoNodo[SIG] = nodo[SIG];
                        nodo[SIG] = nuevoNodo;
                    }
                } else {
                    void **nodo = (void **) (nodoEsp[PRI2]);
                    nuevoNodo[SIG] = nodo[SIG];
                    nodo[SIG] = nuevoNodo;
                }
                break;
            case 1:
                if (nodoEsp[PRI1] == nullptr) {
                    nodoEsp[PRI1] = nuevoNodo;
                    if (nodoEsp[PRI2] == nullptr) {
                        //AQui
                        if (nodoEsp[PRI3] == nullptr) {
                            nodoEsp[PRI3] = nuevoNodo;
                            nuevoNodo[SIG] = nodoEsp[CABEZA];
                            nodoEsp[CABEZA] = nuevoNodo;



                        }




                        nuevoNodo[SIG] = nodoEsp[CABEZA];
                        nodoEsp[CABEZA] = nuevoNodo;
                    } else {
                        void **nodo = (void **) (nodoEsp[PRI3]);
                        nuevoNodo[SIG] = nodo[SIG];
                        nodo[SIG] = nuevoNodo;
                    }
                } else {
                    void **nodo = (void **) (nodoEsp[PRI2]);
                    nuevoNodo[SIG] = nodo[SIG];
                    nodo[SIG] = nuevoNodo;
                }
                break;
        }



    }
}

bool colaVacia(void *cola) {
    void **nodoEsp = (void **) cola;
    if (nodoEsp[CABEZA] == nullptr)return true;
    return false;
}