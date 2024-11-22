

/* 
 * File:   Cola.h
 * Author: andre
 *
 * Created on 21 de noviembre de 2024, 08:10 PM
 */

#ifndef COLA_H
#define COLA_H

#include "Nodo.h"


class Cola {
public:
    Cola();
    Cola(const Cola& orig);
    virtual ~Cola();
    //
    bool esColaVacia();
    void encolar(ClDatos &elemento);
    ClDatos desencolar();
    ClDatos retornaCabeza();
    void eliminarCabeza();
    
    
    void destruirCola();
private:
    Nodo *cabeza;//Primer Nodo
    Nodo *cola;//Ultimo Nodo
    int longitud;
};

#endif /* COLA_H */

