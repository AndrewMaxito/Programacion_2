
/* 
 * File:   Farmacia.h
 * Author: andre
 *
 * Created on 28 de mayo de 2024, 12:43
 */

#ifndef FARMACIA_H
#define FARMACIA_H
#include <fstream>
using namespace std;
#include "Medico.h"
#include "Medicamentos.h"
#include "Conreceta.h"
#include "Sinreceta.h"

class Farmacia {
private:
    class Medico lmedico[300];
    class Sinreceta lsinreceta[1000];
    class Conreceta lconreceta[1000];
public:
    //
    void cargamedico(const char*nombArch);
    void leerecetas(const char*nombArchRec,const char*nombArchMedica);
    void imprimerecetas(const char *nombArch);
    
    
    void imprimeLineas(ofstream& arch,char ,int );

};

#endif /* FARMACIA_H */

