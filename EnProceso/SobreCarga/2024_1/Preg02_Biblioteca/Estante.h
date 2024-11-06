
/* 
 * File:   Estante.h
 * Author: andre
 *
 * Created on 30 de octubre de 2024, 11:30
 */

#ifndef ESTANTE_H
#define ESTANTE_H
#include <fstream>
using namespace std;

#include "Libro.h"
#include "Espacio.h"


class Estante {
public:
    Estante();
    virtual ~Estante();
    void SetCantidad_libros(int cantidad_libros);
    int GetCantidad_libros() const;
    void SetAltura(int altura);
    int GetAltura() const;
    void SetAnchura(int anchura);
    int GetAnchura() const;
    void SetCodigo(const char* cad);
    void GetCodigo(char *cad) const;
    //
    bool operator += (class Libro &lib);
    void espaciosEstantes(int altura,int anchura);
//    int metodoEspacioAnchoDisponible();
    int metodoEspacioLibreAncho();
    void modificarEspacios(int posxLibre,int anchoLib,int altoLib);
    void imprimeEstantes(ofstream &arch,int i,int j);
    void imprimirLibros(ofstream &arch,int i);
private:
    char *codigo;
    int anchura;
    int altura;
    class Libro libros[100];
    class Espacio *espacios;//aca no se si es *espacios[10]
    int cantidad_libros;
};

void operator >> (ifstream &arch,class Estante &estan);
void operator << (ofstream &arch,class Estante &estan);
#endif /* ESTANTE_H */

