

/* 
 * File:   Novela.h
 * Author: andre
 *
 * Created on 7 de noviembre de 2024, 11:50
 */

#ifndef NOVELA_H
#define NOVELA_H

#include <fstream>

#include "Libro.h"

class Novela : public Libro {
public:
    Novela();
    Novela(const Novela& orig);
    virtual ~Novela();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetTipo(const char* cad);
    void GetTipo(char *cad) const;
    //
    void leerDatosNovela(ifstream &arch);

private:
    char *tipo;
    double peso;
};

#endif /* NOVELA_H */

