

/* 
 * File:   funcionesLista.cpp
 * Author: andre
 * 
 * Created on 24 de octubre de 2024, 16:56
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "funcionesLista.h"

enum NODOESP {
    CABEZA, COLA, CANT
};

enum NODO {
    DAT, SIG
};

void crearLista(void *&listaPlatos, void *(*leerRegistro)(ifstream &arch), const char* nomArch) {
    ifstream arch(nomArch, ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }

    listaPlatos = cosntruirLista();
    void *dato;
    while (true) {
        dato = leerRegistro(arch);
        if (dato == nullptr) break;
        insertaLista(listaPlatos, dato);
    }
}

void *cosntruirLista() {
    void **nodoEsp = new void *[3];
    nodoEsp[CABEZA] = nullptr;
    nodoEsp[COLA] = nullptr;
    nodoEsp[CANT] = new int (0);
    return nodoEsp;
}

void insertaLista(void *listaPlatos, void *dato) {
    void **nuevoNodo = new void *[2] {
    }; //apunta a nullptr pro defecto
    nuevoNodo[DAT] = dato;
    void **nodoEsp = (void **) listaPlatos;
    if (esListaVacia(listaPlatos)) {
        nodoEsp[CABEZA] = nuevoNodo;
    } else {
        void **ultimoNodo = (void **) (nodoEsp[COLA]);
        ultimoNodo[SIG] = nuevoNodo;
    }
    nodoEsp[COLA] = nuevoNodo;
    int *cant = (int *) (nodoEsp[CANT]);
    (*cant)++;
}

bool esListaVacia(void *listaPlatos) {
    void **nodoEsp = (void **) listaPlatos;
    if (nodoEsp[CABEZA] == nullptr)return true;
    return false;
}

//15290194  BR-283    1    MCE193    11.69
//    80694546     BE-987    2    SRY667    1.01

void actualizarLista(void *listaPlatos, const char *nomArch) {
    ifstream arch(nomArch, ios::in);
    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }

    int dni, num;
    char buffCodPla[7];
    char buffCodRep[7];
    double precio;

    while (true) {
        arch >> dni;
        if (arch.eof())break;
        arch >> buffCodPla >> num >> buffCodRep >> precio;
        
        void *nodoPlato = buscaNodoPlato(listaPlatos, buffCodPla);
        
        if (nodoPlato != nullptr){ // plato encontrado
            void **regDatPla = (void **) (nodoPlato);
            void **datPlat = (void **)(regDatPla[0]);
            int *cantPlatoPedi = (int *)(datPlat[1]);
            void **regDnis = (void **)(regDatPla[1]);
            regDnis[*cantPlatoPedi] = new int (dni);
            (*cantPlatoPedi)++;
        }
    }
}

void *buscaNodoPlato(void *listaPlatos, char *buffCodPla) {
    void **nodoEsp = (void **) listaPlatos;
    void **recorrido = (void **) (nodoEsp[CABEZA]);
    
    while (recorrido != nullptr) {
        
        void **regDatPla = (void **) (recorrido[DAT]);
        void **datoPlato = (void **) (regDatPla[0]);
        char *codigo = (char *) (datoPlato[0]);
        if (strcmp(codigo, buffCodPla) == 0) return recorrido[DAT]; //ddevulve el nodo que tiene el dato
        recorrido = (void **)(recorrido[SIG]);
    }
    cout <<"no se encontro el plato "<<buffCodPla<<endl;
    return nullptr; //si no encuentra el plato
}