

/* 
 * File:   listas_genericas.cpp
 * Author: andre
 * 
 * Created on 9 de octubre de 2024, 19:57
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "listas_genericas.h"

enum NODO {
    DATO, SIG
};

enum DATOSHEROE {
    CODIGO, NOMBRE, ROL, CATEGORIA, PUNTAJE
};

void *leer_heroe(void *regHer) {
    void **datosHeroe = (void **) (regHer);
    return datosHeroe; //la verdad me parece una funcion muy tonta pero bueno XD
}

void crear_lista_heroes(void *arreglo_heroes, void *&lista_heroes, void *(*leer_heroe)(void *regisHer)) {

    void **nodoFinal = nullptr;
    lista_heroes = nullptr;

    void **regHeroe = (void **) (arreglo_heroes);
    for (int i = 0; regHeroe[i]; i++) {
        void **nuevoNodo = new void *[2] {
        };
        nuevoNodo[DATO] = leer_heroe(regHeroe[i]);
        if (lista_heroes == nullptr) lista_heroes = nuevoNodo;
        else nodoFinal[SIG] = nuevoNodo;
        nodoFinal = nuevoNodo;
    }
}

void imprimir_registro_heroe(ofstream &arch, void *dato) {
    void **datosHeroe = (void **) dato;
    int *codigo = (int *) (datosHeroe[CODIGO]);
    char *nombre = (char *) (datosHeroe[NOMBRE]);
    char *rol = (char *) (datosHeroe[ROL]);
    char *categoria = (char *) (datosHeroe[CATEGORIA]);
    double *puntaje = (double *) (datosHeroe[PUNTAJE]);

    arch << left << setw(15) << nombre << setw(17) << rol << setw(13) << categoria << right <<
            setw(5) << *puntaje << setw(10) << *codigo << endl;
}

void imprimir_lista_heroes(void *lista_heroes, void (*imprimir_registro_heroe)(ofstream &, void *), const char*nomArch) {
    ofstream arch(nomArch, ios::out);
    if (not arch.is_open()) {
        cout << "No se pudo abrir el archivo " << nomArch << endl;
    }
    void **recorrido = (void **) (lista_heroes);
    arch << left << setw(15) << "Nombre" << setw(17) << "ROL" << setw(14) << 
            "Categoria" << setw(10) << "Puntaje" << "Codigo"<<endl;
    imprimirLineas(arch,65,'=');
    while (recorrido) {
        imprimir_registro_heroe(arch, recorrido[DATO]);
        recorrido = (void **) (recorrido[SIG]);
    }
}

void eliminar_registro(void *actual, void *&siguiente) {
    void **nodoAct = (void **) actual;
    void **nodoSigu = (void **) siguiente;

    if (nodoSigu != nullptr) {//se debe verificar que el posterior (ultimo) no es nullo
        void **datoSig = (void **) (nodoSigu[DATO]);
        void **datoAct = (void **) (nodoAct[DATO]);

        char *nombreSig = (char *) (datoSig[NOMBRE]);
        char *nombreAct = (char *) (datoAct[NOMBRE]);


        while (strcmp(nombreAct, nombreSig) == 0) { //por si existen mas de 2
            // Como esta ordenado el actual simpre tendra mayor puntaje por eso simpre se elimina el siguiente
            nodoAct[SIG] = nodoSigu[SIG];
            delete [] nodoSigu;
            //se le vuelve a asignar el nuevo siguiente
            nodoSigu = (void **) nodoAct[SIG];
            if (nodoSigu == nullptr) break;
            datoSig = (void **) (nodoSigu[DATO]);
            nombreSig = (char *) (datoSig[NOMBRE]);
        }
    }
}

void eliminar_lista_heroes_repetidos(void *&lista_heroes, void (*eliminar_registro)(void *, void*&)) {
    void *actual = lista_heroes; //este hara el recorrido
    void *siguiente = nullptr;
    while (actual) {
        void **nodoActual = (void **) (actual);
        siguiente = nodoActual[SIG];
        eliminar_registro(actual, siguiente); //si se elimina algo solo se eliminara el registro actual
        actual = (void **) (nodoActual[SIG]);
    }
}


void imprimirLineas(ofstream &arch,int cant,char car){
    for (int i = 0; i <cant; i++) arch<<car;
    arch<<endl;
}