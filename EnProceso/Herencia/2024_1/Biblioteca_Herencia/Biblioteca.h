
/* 
 * File:   Biblioteca.h
 * Author: andre
 *
 * Created on 7 de noviembre de 2024, 12:10
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "EstanteVertical.h"
#include "EstanteHorizontal.h"
#include "Enciclopedia.h"

class Biblioteca {
public:
    Biblioteca();
    void SetCantidad_total_Novelas(int cantidad_total_Novelas);
    int GetCantidad_total_Novelas() const;
    void SetCantidad_total_enciclopedias(int cantidad_total_enciclopedias);
    int GetCantidad_total_enciclopedias() const;
    void SetCantidad_estantes_Horizontales(int cantidad_estantes_Horizontales);
    int GetCantidad_estantes_Horizontales() const;
    void SetCantidad_estantes_verticales(int cantidad_estantes_verticales);
    int GetCantidad_estantes_verticales() const;
    //
    void cargar_libros();
    void cargar_estantes();
    //void posicionar_libros();
    
private:
    EstanteVertical estanteVerticales[20];
    int cantidad_estantes_verticales;
    EstanteHorizontal estanteHorizontales[20];
    int cantidad_estantes_Horizontales;
    Enciclopedia enciclopedias[20];
    int cantidad_total_enciclopedias;
    Novela novelas[20];
    int cantidad_total_Novelas;
};

#endif /* BIBLIOTECA_H */

