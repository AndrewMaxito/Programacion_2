

/* 
 * File:   PedidoEventual.h
 * Author: andre
 *
 * Created on 19 de noviembre de 2024, 16:09
 */

#ifndef PEDIDOEVENTUAL_H
#define PEDIDOEVENTUAL_H

#include "Pedido.h"


class PedidoEventual: public Pedido {
public:
    PedidoEventual();
    void lee(ifstream& arch, int codigo) override;

private:
    double flete;
};

#endif /* PEDIDOEVENTUAL_H */

