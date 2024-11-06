

/* 
 * File:   Virtual.h
 * Author: andre
 *
 * Created on 5 de noviembre de 2024, 16:31
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H
#include <fstream>
using namespace std;
#include "Alumno.h"


class Virtual : public Alumno{
public:
    Virtual();
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(const char* cad);
    void GetLicencia(char *cad) const;
    //
    void leerDatos(ifstream &arch);
    void actualiza(double monto);
    void imprime(ofstream& arch);
private:
    char *licencia;
    double total;
};

#endif /* VIRTUAL_H */

