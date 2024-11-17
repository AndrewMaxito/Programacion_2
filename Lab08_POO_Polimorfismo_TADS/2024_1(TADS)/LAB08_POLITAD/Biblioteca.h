

/* 
 * File:   Biblioteca.h
 * Author: andre
 *
 * Created on 17 de noviembre de 2024, 01:50 PM
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Estante.h"


class Biblioteca {
public: 
    void carga();
    void llena();
    void baja();
    void muestra();
    void imprimirLineas(ofstream &arch,int cant,char car);
private:
    Estante AEstenates[10];
    
};

#endif /* BIBLIOTECA_H */

