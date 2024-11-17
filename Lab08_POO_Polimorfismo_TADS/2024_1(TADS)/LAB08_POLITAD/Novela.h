

/* 
 * File:   Novela.h
 * Author: andre
 *
 * Created on 17 de noviembre de 2024, 12:37 PM
 */

#ifndef NOVELA_H
#define NOVELA_H

#include "Libro.h"

class Novela : public Libro {
public:
    Novela();
    virtual ~Novela();
    void SetAutor(const char* cad);
    void lee(ifstream& arch) override;
    void actualiza() override;
    void imprime(ofstream& arch) override;
private:
    char *autor;
};

#endif /* NOVELA_H */

