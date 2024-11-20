
/* 
 * File:   Lista.h
 * Author: andre
 *
 * Created on 19 de noviembre de 2024, 16:13
 */

#ifndef LISTA_H
#define LISTA_H

#include <fstream>
using namespace std;
#include "Nodo.h"


class Lista {
public:
    Lista();
    virtual ~Lista();
    void insertarOrdenado(Pedido *pedido);
    bool esListaVacia();
    void imprimirLista(ofstream &arch);
    void modificarFlete(int dniPer,int fecha);
    
    
    
    
private:
    Nodo *lini;
    Nodo *lfin;
};

#endif /* LISTA_H */

