

/* 
 * File:   Semipresencial.h
 * Author: andre
 *
 * Created on 11 de junio de 2024, 18:19
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H

#include "Boleta.h"


class Semipresencial: public Alumno {
private:
    double descuento;
    double total;

public:
    Semipresencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    //
    void leer(ifstream &);
     void imprime(ofstream &arch);
    

};

#endif /* SEMIPRESENCIAL_H */

