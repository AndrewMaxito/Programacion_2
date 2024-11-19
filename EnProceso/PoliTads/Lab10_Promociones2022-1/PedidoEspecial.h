
/* 
 * File:   PedidoEspecial.h
 * Author: andre
 *
 * Created on 19 de noviembre de 2024, 16:05
 */

#ifndef PEDIDOESPECIAL_H
#define PEDIDOESPECIAL_H

#include "Pedido.h"


class PedidoEspecial: public Pedido {
public:
    PedidoEspecial();
    void lee(ifstream& arch,int codigo) override;

private:
    double descuento;

};

#endif /* PEDIDOESPECIAL_H */

