
/* 
 * File:   Presencial.h
 * Author: andre
 *
 * Created on 5 de noviembre de 2024, 16:27
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H

#include <fstream>
using namespace std;
#include "Alumno.h"


class Presencial : public Alumno {
public:
    Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    //
    void leerDatos(ifstream &arch);
    void actualiza(double monto);
    void imprime(ofstream& arch);
    
private:
    double recargo;
    double total;
};

#endif /* PRESENCIAL_H */

