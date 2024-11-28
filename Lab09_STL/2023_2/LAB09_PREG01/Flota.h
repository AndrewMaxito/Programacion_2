

/* 
 * File:   Flota.h
 * Author: andre
 *
 * Created on 27 de noviembre de 2024, 09:26 PM
 */

#ifndef FLOTA_H
#define FLOTA_H
#include <vector>

#include "NVehiculo.h"
using namespace std;
class Flota {
public:
    Flota();
    Flota(const Flota& orig);
    virtual ~Flota();
    //
    void cargaFlota();
    void cargaPedidos();
    void muestraCarga();
    
    
private:
    vector<NVehiculo>vFlota;
    void imprimiLineas(ofstream &arch,int cant,char car);
    int buscarVehiculo(int Idcliente);
};

#endif /* FLOTA_H */

