
/* 
 * File:   PedidoUsual.h
 * Author: andre
 *
 * Created on 19 de noviembre de 2024, 16:07
 */

#ifndef PEDIDOUSUAL_H
#define PEDIDOUSUAL_H
#include <fstream>
using namespace std;

#include "Pedido.h"


class PedidoUsual: public Pedido {
public:
    PedidoUsual();
    void lee(ifstream& arch, int codigo) override;

    
private:
    double descuento;
    double flete;

};

#endif /* PEDIDOUSUAL_H */

