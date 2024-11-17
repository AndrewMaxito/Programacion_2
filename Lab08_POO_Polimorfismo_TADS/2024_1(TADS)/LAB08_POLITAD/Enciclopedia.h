

/* 
 * File:   Enciclopedia.h
 * Author: andre
 *
 * Created on 17 de noviembre de 2024, 12:35 PM
 */

#ifndef ENCICLOPEDIA_H
#define ENCICLOPEDIA_H

#include "Libro.h"


class Enciclopedia : public Libro{
public:
    Enciclopedia();
    void lee(ifstream &arch)override;
    void actualiza() override;
    void imprime(ofstream& arch) override;

private:
    int sku;
    int anho;
    int vigencia;
};

#endif /* ENCICLOPEDIA_H */

