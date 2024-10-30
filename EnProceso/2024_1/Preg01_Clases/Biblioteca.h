
/* 
 * File:   Biblioteca.h
 * Author: andre
 *
 * Created on 30 de octubre de 2024, 11:50
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Estante.h"
#include "Libro.h"

class Biblioteca {
public:
    Biblioteca();
   
    virtual ~Biblioteca();
    void SetCantidad_libros(int cantidad_libros);
    int GetCantidad_libros() const;
    void SetCantidad_estantes(int cantidad_estantes);
    int GetCantidad_estantes() const;
private:
    class Estante estantes[50];
    int cantidad_estantes;
    class Libro libros[100];
    int cantidad_libros;
};

#endif /* BIBLIOTECA_H */

