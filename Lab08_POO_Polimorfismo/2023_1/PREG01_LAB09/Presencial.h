

/* 
 * File:   Presencial.h
 * Author: andre
 *
 * Created on 11 de junio de 2024, 18:19
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H

#include "Alumno.h"


class Presencial: public Alumno {
private:
    double recargo;
    double total;
    
public:
    Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    //
    void leer(ifstream &);
     void imprime(ofstream &arch);
};

#endif /* PRESENCIAL_H */

