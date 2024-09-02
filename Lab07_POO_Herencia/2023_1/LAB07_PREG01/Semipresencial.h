
/* 
 * File:   Semipresencial.h
 * Author: andre
 *
 * Created on 27 de mayo de 2024, 18:34
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H
#include <fstream>
using namespace std;

#include "Alumno.h"

class Semipresencial : public Alumno {
private:
    double descueto;
    double total;

public:
    Semipresencial();
    void setTotal(double total);
    double getTotal() const;
    void setDescueto(double descueto);
    double getDescueto() const;

    //
    void leerDatos(ifstream& arch);
    void actualiza(double monto);
    void imprime(ofstream& arch);

};

#endif /* SEMIPRESENCIAL_H */

