

/* 
 * File:   Nodo.h
 * Author: andre
 *
 * Created on 20 de noviembre de 2024, 09:38 PM
 */

#ifndef NODO_H
#define NODO_H

#include "ClDatos.h"


class Nodo {
public:
    Nodo();
    //
    friend class Pila;
private:
    ClDatos dato;
    Nodo *siguiente;
};

#endif /* NODO_H */

