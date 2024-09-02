

/* 
 * File:   Virtual.h
 * Author: andre
 *
 * Created on 27 de mayo de 2024, 18:36
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H

#include "Alumno.h"


class Virtual : public Alumno{
private:
    char* licencia;
    double total;

public:
    Virtual();
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(const char* cad);
    void GetLicencia(char *cad) const;
    
    //
    void leerDatos(ifstream& arch);
    void actualiza(double  monto);
    void imprime(ofstream& arch);

};

#endif /* VIRTUAL_H */

