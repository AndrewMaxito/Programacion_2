
/* 
 * File:   ClienteA.h
 * Author: andre
 *
 * Created on 12 de noviembre de 2024, 14:38
 */

#ifndef CLIENTEA_H
#define CLIENTEA_H

#include "Cliente.h"


class ClienteA : public Cliente {
public:
    ClienteA();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    //
    void lee(ifstream &arch,char catego) override;
    void imprime(ofstream &arch, double desc, double flete)override;
    void calcula(double monto)override;
    
private:
    double descuento;
};

#endif /* CLIENTEA_H */

