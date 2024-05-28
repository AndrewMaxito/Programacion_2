
/* 
 * File:   Presencial.h
 * Author: andre
 *
 * Created on 27 de mayo de 2024, 18:32
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H
#include <fstream>
using namespace std;
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
    void leerDatos(ifstream& arch);
    void actualiza(double  monto);
    void imprime(ofstream& arch);
};

#endif /* PRESENCIAL_H */

