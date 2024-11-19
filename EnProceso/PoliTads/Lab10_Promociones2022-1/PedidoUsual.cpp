

/* 
 * File:   PedidoUsual.cpp
 * Author: andre
 * 
 * Created on 19 de noviembre de 2024, 16:07
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PedidoUsual.h"

PedidoUsual::PedidoUsual() {
    descuento = 0;
    flete = 0;
}

void PedidoUsual::lee(ifstream& arch, int codigo) {
    char c;
    arch >> descuento >> c >> flete;
    arch.get();
    Pedido::lee(arch,codigo);
}



