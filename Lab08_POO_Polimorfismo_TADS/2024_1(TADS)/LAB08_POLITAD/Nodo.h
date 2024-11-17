

/* 
 * File:   Nodo.h
 * Author: andre
 *
 * Created on 17 de noviembre de 2024, 12:44 PM
 */

#ifndef NODO_H
#define NODO_H

#include "Libro.h"

class Nodo {
public:
    Nodo();
    friend class Lista;
private:
    Libro *plibro;
    Nodo *sig;
};

#endif /* NODO_H */

