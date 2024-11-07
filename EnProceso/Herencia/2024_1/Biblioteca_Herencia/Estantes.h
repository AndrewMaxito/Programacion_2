

/* 
 * File:   Estantes.h
 * Author: andre
 *
 * Created on 7 de noviembre de 2024, 11:56
 */

#ifndef ESTANTES_H
#define ESTANTES_H

#include <fstream>
using namespace std;
#include "Espacio.h"

class Estantes {
public:
    Estantes();
    virtual ~Estantes();
    void SetPesoActual(double pesoActual);
    double GetPesoActual() const;
    void SetPesoSoportado(double pesoSoportado);
    double GetPesoSoportado() const;
    void SetAltura(int altura);
    int GetAltura() const;
    void SetAnchura(int anchura);
    int GetAnchura() const;
    void SetCodigo(const char* cad);
    void GetCodigo(char *cad) const;
    //
    void leerDatosEstante(ifstream &arch);
    
private:
    char *codigo;
    int anchura;
    int altura;
    Espacio *espacios;
    double pesoSoportado;
    double pesoActual;
};

#endif /* ESTANTES_H */

