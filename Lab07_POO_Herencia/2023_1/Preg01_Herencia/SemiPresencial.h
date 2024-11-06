
/* 
 * File:   SemiPresencial.h
 * Author: andre
 *
 * Created on 5 de noviembre de 2024, 16:30
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H
#include <fstream>
using namespace std;
#include "Alumno.h"


class SemiPresencial : public Alumno{
public:
    SemiPresencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    //
    void leerDatos(ifstream &arch);
    void actualiza(double monto);
    void imprime(ofstream& arch);
private:
    double descuento;
    double total;

};

#endif /* SEMIPRESENCIAL_H */

