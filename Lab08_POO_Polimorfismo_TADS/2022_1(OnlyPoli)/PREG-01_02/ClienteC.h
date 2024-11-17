

/* 
 * File:   ClienteC.h
 * Author: andre
 *
 * Created on 12 de noviembre de 2024, 14:41
 */

#ifndef CLIENTEC_H
#define CLIENTEC_H

#include "Cliente.h"


class ClienteC: public Cliente {
public:
    ClienteC();
    void SetFlete(double flete);
    double GetFlete() const;
    //
    void lee(ifstream &arch,char catego)override;
    void imprime(ofstream& arch, double descuento, double flete)override;
    void calcula(double monto)override;
    
    
private:
    double flete;
};

#endif /* CLIENTEC_H */

