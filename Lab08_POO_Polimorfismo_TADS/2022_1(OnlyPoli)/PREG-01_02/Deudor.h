
/* 
 * File:   Deudor.h
 * Author: andre
 *
 * Created on 12 de noviembre de 2024, 14:46
 */

#ifndef DEUDOR_H
#define DEUDOR_H

#include <fstream>
using namespace std;
#include "Cliente.h"


class Deudor {
public:
    Deudor();
    Deudor(const Deudor& orig);
    virtual ~Deudor();
    void cargarDatos(char catego,ifstream &arch);
    //
    void muestraDatosDeudor(ofstream &arch);
    bool existe();
    int getCodDni();
    void actualizadeudor(double monto);
    
private:
    Cliente *Cdeudor;
};

bool operator >> (ifstream &arch,Deudor &deudor);

#endif /* DEUDOR_H */

