

/* 
 * File:   Furgon.h
 * Author: andre
 *
 * Created on 27 de noviembre de 2024, 09:19 PM
 */

#ifndef FURGON_H
#define FURGON_H
#include <list>

#include "NPedido.h"
#include "Vehiculo.h"
using namespace std;
class Furgon: public Vehiculo{
public:
    Furgon();
    Furgon(const Furgon& orig);
    virtual ~Furgon();
    //
    void lee(ifstream& arch) override;
    void imprime(ofstream& arch) const override;
    void cargaDeposito(NPedido& ped) override;



private:
    int filas;
    int puertas;
    list<NPedido>pDeposito;
};

#endif /* FURGON_H */

