

/* 
 * File:   Lista.h
 * Author: andre
 *
 * Created on 17 de noviembre de 2024, 01:03 PM
 */

#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"


class Lista {
public:
    Lista();
    virtual ~Lista();
    double GetPeso() const;
    void inserta(Libro *libroLeido);
    bool esListaVacia();
    void analizarVigenciaLibros();
    void mostrarLista(ofstream &arch);
private:
    double Peso;
    Nodo *ini;
};

#endif /* LISTA_H */

