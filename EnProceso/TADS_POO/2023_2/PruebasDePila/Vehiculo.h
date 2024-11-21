

/* 
 * File:   Vehiculo.h
 * Author: andre
 *
 * Created on 20 de noviembre de 2024, 09:05 PM
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include "NPedido.h"


class Vehiculo {
public:
    Vehiculo();
    Vehiculo(const Vehiculo& orig);
    virtual ~Vehiculo();
    void eliminar();
private:
    int cliente;
    char *placa;
    double maxcarga;
    double actcarga;
    NPedido *ped;
};

#endif /* VEHICULO_H */

