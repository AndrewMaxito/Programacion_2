
/* 
 * File:   Lista.cpp
 * Author: andre
 * 
 * Created on 17 de noviembre de 2024, 01:03 PM
 */

#include "Lista.h"

Lista::Lista() {
    Peso = 0;
    ini = nullptr;
}

Lista::~Lista() {
    Nodo *recorrido = ini;
    while (recorrido != nullptr) {
        Nodo *nodoAEliminar = recorrido;
        recorrido = recorrido->sig;
        delete nodoAEliminar->plibro;
        delete nodoAEliminar;
    }
}

double Lista::GetPeso() const {
    return Peso;
}

void Lista::inserta(Libro* libroLeido) {
    Nodo *nuevoNodo = new Nodo;
    nuevoNodo->plibro = libroLeido;
    if (esListaVacia()){
        ini = nuevoNodo;
    }else{
        Nodo *recorrido = ini;
        while (recorrido->sig !=nullptr) {
            recorrido = recorrido->sig;
        }
        recorrido->sig = nuevoNodo;
    }
    Peso += libroLeido->GetPeso();
}

bool Lista::esListaVacia() {
    return ini==nullptr;
}

void Lista::analizarVigenciaLibros() {
    Nodo *recorrer = ini;
    while (recorrer) {
        recorrer->plibro->actualiza();
        recorrer = recorrer->sig;
    }
}

void Lista::mostrarLista(ofstream& arch) {
    Nodo *recorrer = ini;
    while (recorrer) {
        recorrer->plibro->imprime(arch);
        recorrer = recorrer->sig;
        arch<<endl;
    }
}




