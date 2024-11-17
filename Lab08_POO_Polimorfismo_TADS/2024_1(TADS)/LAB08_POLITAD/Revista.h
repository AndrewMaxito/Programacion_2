

/* 
 * File:   Revista.h
 * Author: andre
 *
 * Created on 17 de noviembre de 2024, 12:41 PM
 */

#ifndef REVISTA_H
#define REVISTA_H

#include "Libro.h"


class Revista : public Libro{
public:
    Revista();
    void lee(ifstream& arch) override;
    void actualiza() override;
    void imprime(ofstream& arch) override;

private:
    int ISSN;
    int anho;
    int numero;
    int vigencia;
};

#endif /* REVISTA_H */

