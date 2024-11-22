
/* 
 * File:   Nodo.h
 * Author: andre
 *
 * Created on 21 de noviembre de 2024, 08:15 PM
 */

#ifndef NODO_H
#define NODO_H

#include "ClDatos.h"


class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    friend class Cola;
private:
    ClDatos elemento;
    Nodo *siguiente;
};

#endif /* NODO_H */

