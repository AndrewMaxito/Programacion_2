
/* 
 * File:   PedidoEspecial.cpp
 * Author: andre
 * 
 * Created on 19 de noviembre de 2024, 16:05
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PedidoEspecial.h"

PedidoEspecial::PedidoEspecial() {
    descuento = 0;
}

void PedidoEspecial::lee(ifstream& arch, int codigo) {
    arch >> descuento;
    arch.get();
    Pedido::lee(arch,codigo);
}
