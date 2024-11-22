/* 
 * File:   Registros.h
 * Author: andre
 *
 * Created on 21 de noviembre de 2024, 03:41 PM
 */

#ifndef REGISTROS_H
#define REGISTROS_H

#include "ClDatos.h"
#include "Pila.h"


class Registros {
public:
    Registros();
    void SetCantidadDatos(int cantidadDatos);
    int GetCantidadDatos() const;
    //
    void cargarDatos();
    void UsoTad();
    void sacarDatosTad();
private:
    ClDatos datos[10];
    int cantidadDatos;
    Pila pilaDatos;

};

#endif /* REGISTROS_H */

