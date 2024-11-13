
/* 
 * File:   ClienteB.h
 * Author: andre
 *
 * Created on 12 de noviembre de 2024, 14:39
 */

#ifndef CLIENTEB_H
#define CLIENTEB_H
#include <fstream>
using namespace std;
#include "Cliente.h"

class ClienteB : public Cliente {
public:
    ClienteB();
    void SetFlete(double flete);
    double GetFlete() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    //
    void lee(ifstream &arch, char catego)override;
    void imprime(ofstream& arch, double descuento, double flete)override;
    void calcula(double monto)override;


private:
    double descuento;
    double flete;

};

#endif /* CLIENTEB_H */

