
/* 
 * File:   Libro.h
 * Author: andre
 *
 * Created on 30 de octubre de 2024, 11:21
 */

#ifndef LIBRO_H
#define LIBRO_H

#include <fstream>
using namespace std;

class Libro {
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetColocado(bool colocado);
    bool IsColocado() const;
    void SetAlto(int alto);
    int GetAlto() const;
    void SetAncho(int ancho);
    int GetAncho() const;
    
    void SetNombre(const char* cad);
    void GetNombre(char *cad) const;
    void SetCodigo(const char* cad) ;
    void GetCodigo(char *cad) const;
private:
    char *codigo;
    char *nombre;
    int ancho;
    int alto;
    bool colocado;
};
void operator >> (ifstream &arch,class Libro &lib);

#endif /* LIBRO_H */

