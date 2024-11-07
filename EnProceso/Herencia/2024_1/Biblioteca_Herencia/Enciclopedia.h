

/* 
 * File:   Enciclopedia.h
 * Author: andre
 *
 * Created on 7 de noviembre de 2024, 11:48
 */

#ifndef ENCICLOPEDIA_H
#define ENCICLOPEDIA_H

#include "Libro.h"


class Enciclopedia : public Libro {
public:
    Enciclopedia();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetVolumen(int volumen);
    int GetVolumen() const;
    //
    void leeDatosEnciclopedia(ifstream &arch);
private:
    int volumen;
    double peso;
};

#endif /* ENCICLOPEDIA_H */

