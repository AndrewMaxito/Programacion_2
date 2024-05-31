
/* 
 * File:   Conreceta.h
 * Author: andre
 *
 * Created on 28 de mayo de 2024, 12:39
 */

#ifndef CONRECETA_H
#define CONRECETA_H
#include <fstream>
using namespace std;
#include "Medicamentos.h"


class Conreceta: public Medicamentos {
private:
    //Datos con receta
    int codmed;
    char* especialidad;
    

public:
    Conreceta();
    virtual ~Conreceta();
    void setEspecialidad(const char* cad);
    void getEspecialidad(char *cad) const ;
    void setCodmed(int codmed);
    int getCodmed() const;
    //
    
    
   
    




};

#endif /* CONRECETA_H */

