
/* 
 * File:   Tesoreria.h
 * Author: andre
 *
 * Created on 27 de mayo de 2024, 18:38
 */

#ifndef TESORERIA_H
#define TESORERIA_H
#include <fstream>
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"
#include "Escala.h"

using namespace std;
class Tesoreria {
private:
    class Presencial lpresencial[300];
    class Semipresencial lsemipresencial[300];
    class Virtual lvirtual[300];
    class Escala lescala[10]; 
    

public:
    void cargaescalas(const char*);
    void cargaalumnos(const char*);
    void actualiza(double cred);
    void imprime(const char* nomArch);
    

};

#endif /* TESORERIA_H */

