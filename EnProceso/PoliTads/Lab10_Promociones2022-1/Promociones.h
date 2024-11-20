
/* 
 * File:   Promociones.h
 * Author: andre
 *
 * Created on 19 de noviembre de 2024, 16:18
 */

#ifndef PROMOCIONES_H
#define PROMOCIONES_H

#include "Lista.h"


class Promociones {
public:
    void leePedidos();
    void imprimePedidos();
    void imprimeLineas(ofstream &arch,int cant,char car);
    void actualizarPedidos();

private:
    Lista Lpedidos;
};

#endif /* PROMOCIONES_H */

