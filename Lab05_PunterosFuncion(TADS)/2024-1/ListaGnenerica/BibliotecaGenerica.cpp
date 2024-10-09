#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

#include "BibliotecaGenerica.h"

using namespace std;

enum NODOESP {
    CABEZA, COLA
};

enum NODO {
    DATO, NEXT
};

void crealista(void *&pedidos1, void *(*leeRegistro)(ifstream &), const char *nomArch) {

    ifstream arch(nomArch, ios::in);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    void **nodoEspecial = new void *[2] {
    }; //creacion del nodo especial 
    void *datos;

    while (true) {
        datos = leeRegistro(arch);
        if (datos == nullptr) break;
        insertarlista(datos, nodoEspecial);
        pedidos1 = nodoEspecial;
    }
}

void insertarlista(void *datos, void **nodoEspecial) {
    void **nodoNuevo, **colaEspecial;

    nodoNuevo = new void *[2] {
    };
    nodoNuevo[DATO] = datos;

    if (nodoEspecial[CABEZA] == nullptr) {
        nodoEspecial[CABEZA] = nodoNuevo;
    } else {
        colaEspecial = (void **) (nodoEspecial[COLA]);
        colaEspecial[NEXT] = nodoNuevo;
    }
    nodoEspecial[COLA] = nodoNuevo;
}

void imprimelista(void *pedidos1, void (*imprimeRegistro)(ofstream &, void *), const char *nomArch) {

    ofstream arch(nomArch, ios::out);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
        exit(1);
    }
    void **nodoEspecial = (void **) pedidos1;
    void **nodo = (void**) (nodoEspecial[CABEZA]);

    while (nodo != nullptr) {
        imprimeRegistro(arch, nodo[DATO]);
        nodo = (void **) (nodo[NEXT]);
    }
}

void combinalista(void *pedidos1, void *pedidos2, void *&pedidiosFinal,
        int (*cmpReg)(void *, void*)) {

    void **nodoEspecial = new void *[2] {
    };

    void **especial1 = (void **) pedidos1, **especial2 = (void **) pedidos2;
    void **nodo1, **nodo2;
    void *dato;

    while (especial1[COLA] != nullptr or especial2[COLA] != nullptr) {
        if (especial1[COLA] == nullptr) {
            while (especial2[COLA] != nullptr) {
                dato = quitarlista(especial2);
                insertarlista(dato, nodoEspecial);
            }
            break;
        }
        if (especial2[COLA] == nullptr) {
            while (especial1[COLA] != nullptr) {
                dato = quitarlista(especial1);
                insertarlista(dato, nodoEspecial);
            }
            break;
        }
        nodo1 = (void**) (especial1[CABEZA]);
        nodo2 = (void**) (especial2[CABEZA]);
        int cmpResult = cmpReg(nodo1[DATO], nodo2[DATO]);

        if (cmpResult <= 0) {
            if (cmpResult == 0) {
                void **basura = (void **) (quitarlista(especial2));
                delete[] basura;
            }
            dato = quitarlista(especial1);
        } else {
            dato = quitarlista(especial2);
        }
        insertarlista(dato, nodoEspecial);
    }
    pedidiosFinal = nodoEspecial;
}

void *quitarlista(void **especial) {
    void **nodo = (void**) (especial[CABEZA]);
    void *registroDatos = nodo[DATO];
    especial[CABEZA] = nodo[NEXT];
    if (especial[CABEZA] == nullptr) especial[COLA] = nullptr;
    nodo =nullptr;
//    delete nodo; // solo tengo dudas con la eliminacion del nodo (se elimina el registro si borro el nodo ? o solo se libera el espacio de memoria del nodo dejando el registro intacto)
    return registroDatos;
}





