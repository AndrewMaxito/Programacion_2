

/* 
 * File:   Libro.h
 * Author: andre
 *
 * Created on 7 de noviembre de 2024, 11:39
 */

#ifndef LIBRO_H
#define LIBRO_H

#include <fstream>
using namespace std;


class Libro {
public:
    Libro();
    virtual ~Libro();
    void SetColocado(bool colocado);
    bool IsColocado() const;
    void SetPeso(double peso);
    double GetPeso() const;
    void SetAlto(int alto);
    int GetAlto() const;
    void SetAncho(int ancho);
    int GetAncho() const;

    void SetNombre(const char* cad);
    void GetNombre(char *cad) const;
    void SetCodigo(const char* cad);
    void GetCodigo(char *cad) const;
    //
    void leerDatos(ifstream &arch);
private:
    char *codigo;
    char *nombre;
    int ancho;
    int alto;
    double peso;
    bool colocado;
};

#endif /* LIBRO_H */

