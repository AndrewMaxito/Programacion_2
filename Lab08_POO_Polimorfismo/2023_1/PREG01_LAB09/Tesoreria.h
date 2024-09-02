

/* 
 * File:   Tesoreria.h
 * Author: andre
 *
 * Created on 11 de junio de 2024, 18:20
 */

#ifndef TESORERIA_H
#define TESORERIA_H
#include "Boleta.h"
#include "Escala.h"

class Tesoreria {
private:
    class Boleta lboleta[100];
    class Escala lescala[10];

public:
    void cargarescalas();
    void cargaralumnos();
    void imprimeboleta();
    

};

#endif /* TESORERIA_H */

