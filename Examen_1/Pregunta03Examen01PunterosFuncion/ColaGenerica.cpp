#include <iostream>
#include <iomanip>

#include "ColaGenerica.h"

using namespace std;

void *generaCola() {
    void **cola = new void *[3] {
    };
    cola[2] = new int (0);
    return cola;
}

void encola(void *cola, void *dato) {
    void **nodoEspecial = (void **) cola;
    int *cantElement = (int *) (nodoEspecial[2]);
    void **nuevoNodo = new void *[2] {
    };
    nuevoNodo[0] = dato;

    if (nodoEspecial[0] == nullptr) {
        nodoEspecial[0] = nuevoNodo;
    } else {
        void **ultimo = (void **) (nodoEspecial[1]);
        ultimo[1] = nuevoNodo;
    }
    nodoEspecial[1] = nuevoNodo;
    (*cantElement)++;
}

bool colavacia(void *cola) {
    void **nodoEspecial = (void **) cola;
    return nodoEspecial[0] == nullptr;
}


void *desencolar(void *cola){
    if (colavacia(cola)) {
        cout << "La cola está vacía, no se puede desencolar." << endl;
        return nullptr;
    }
    void **nodoEspecial=(void **)cola;
    void **primero=(void **)(nodoEspecial[0]);
    void *dato = primero[0];
    
    void **siguienteNodo = (void **)(primero[1]);
    delete []primero;
    nodoEspecial[0]=siguienteNodo;
    
    int *cantElementos = (int *)(nodoEspecial[2]);
    (*cantElementos)--;
    return dato;
}