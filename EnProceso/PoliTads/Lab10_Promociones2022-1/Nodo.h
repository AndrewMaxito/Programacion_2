
/* 
 * File:   Nodo.h
 * Author: andre
 *
 * Created on 19 de noviembre de 2024, 16:11
 */

#ifndef NODO_H
#define NODO_H

#include "Pedido.h"


class Nodo {
public:
    Nodo();
    friend class Lista;
private:
    
    Pedido *ped;
    Nodo *sig;
    Nodo *ant;
};

#endif /* NODO_H */

