

/* 
 * File:   NVehiculo.h
 * Author: andre
 *
 * Created on 27 de noviembre de 2024, 09:24 PM
 */

#ifndef NVEHICULO_H
#define NVEHICULO_H
#include <fstream>
using namespace std;
#include "Vehiculo.h"
#include "NPedido.h"


class NVehiculo {
public:
    NVehiculo();
    NVehiculo(const NVehiculo& orig);
    virtual ~NVehiculo();
    //
    void cargaDatos(ifstream &arch,char tipo);
    void ImprimirDatos(ofstream &arch)const ;
    bool operator<(const NVehiculo& right) const;
    int metodoObtenerDni()const ;
    void agregarPedido(NPedido &aux);

private:
    Vehiculo *unidad;
};
void operator >>(ifstream &arch,NVehiculo &contenedor);
void operator <<(ofstream&arch,NVehiculo &contenedor);

#endif /* NVEHICULO_H */

