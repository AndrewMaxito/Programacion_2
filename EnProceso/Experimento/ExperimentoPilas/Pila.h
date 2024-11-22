/* 
 * File:   Pila.h
 * Author: andre
 *
 * Created on 20 de noviembre de 2024, 09:38 PM
 */

#ifndef PILA_H
#define PILA_H

#include "Nodo.h"


class Pila {
public:
    Pila();
    Pila(const Pila& orig);
    virtual ~Pila();
    //
    bool esPilaVacia()const ;
    void apilar(const ClDatos &dato);
    ClDatos desapilar();
    ClDatos cima();
    void eliminarCabeza();
    void destruir();
    void imprimir();
private:
    Nodo *cabeza;
    int longitud;
};

#endif /* PILA_H */

