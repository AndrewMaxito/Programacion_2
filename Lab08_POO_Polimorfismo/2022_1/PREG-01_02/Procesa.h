

/* 
 * File:   Procesa.h
 * Author: andre
 *
 * Created on 12 de noviembre de 2024, 14:48
 */

#ifndef PROCESA_H
#define PROCESA_H

#include "Pedido.h"
#include "Deudor.h"


class Procesa {
public:
    void carga();
    void muestra();
    void actualiza();
    //
    void imprimirLineas(ofstream &archRep,int cant,char car);
    
    
    
    
    
private:
    Pedido lPedidos[200];
    Deudor lDeudor[200];
};

#endif /* PROCESA_H */

