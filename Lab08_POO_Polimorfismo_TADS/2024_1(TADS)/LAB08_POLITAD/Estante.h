

/* 
 * File:   Estante.h
 * Author: andre
 *
 * Created on 17 de noviembre de 2024, 01:20 PM
 */

#ifndef ESTANTE_H
#define ESTANTE_H

#include "Lista.h"

class Estante {
public:
    Estante();
    void SetCapacidad(double capacidad);
    double GetCapacidad() const;
    void SetId(int id);
    int GetId() const;
    void SetClase(char clase);
    double GetPesoDisponible()const;
    void agregarLibro(Libro *libroLeido);
    void verificarVigencia();
    void imprimirDatosEstante(ofstream &arch);
    void imprimirLineas(ofstream &arch,int cant,char car);
private:
    char clase;
    int id;
    double capacidad;
    Lista Llibros;
};
#endif /* ESTANTE_H */

