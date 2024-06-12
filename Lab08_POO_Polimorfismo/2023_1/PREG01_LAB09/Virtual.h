

/* 
 * File:   Virtual.h
 * Author: andre
 *
 * Created on 11 de junio de 2024, 18:19
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H

#include "Alumno.h"

class Virtual : public Alumno {
private:
    char *licencia;
    double total;

public:
    Virtual();

    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(const char* cad);
    void GetLicencia(char *cad) const;
    //
    void leer(ifstream &);
    void imprime(ofstream &arch);
};

#endif /* VIRTUAL_H */

