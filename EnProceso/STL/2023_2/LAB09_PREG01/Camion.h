
/* 
 * File:   Camion.h
 * Author: andre
 *
 * Created on 27 de noviembre de 2024, 09:06 PM
 */

#ifndef CAMION_H
#define CAMION_H
#include <map>
#include "NPedido.h"
#include "Vehiculo.h"
using namespace std;
class Camion : public Vehiculo {
public:
    Camion();
    Camion(const Camion& orig);
    //
    void lee(ifstream& arch) override;
    void imprime(ofstream& arch) const override;
    void cargaDeposito(NPedido& ped) override;



private:
    int ejes;
    int llantas;
    map<int,NPedido> mDeposito;
    
};

#endif /* CAMION_H */

