

/* 
 * File:   Tesoreria.h
 * Author: andre
 *
 * Created on 5 de noviembre de 2024, 16:36
 */

#ifndef TESORERIA_H
#define TESORERIA_H

#include "Presencial.h"
#include "SemiPresencial.h"
#include "Virtual.h"
#include "Escala.h"


class Tesoreria {
public:
    Tesoreria();
    void cargaEscalas();
    void cargaAlumnos();
    void actualiza(double creditos);
    void imprime(const char* nomArch);
private:
    class Presencial lpresencial[100];
    class SemiPresencial lsemipresencial[100];
    class Virtual lvirtual[100];
    class Escala lescala[20];

};

#endif /* TESORERIA_H */

