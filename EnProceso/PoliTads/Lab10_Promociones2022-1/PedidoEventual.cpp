

/* 
 * File:   PedidoEventual.cpp
 * Author: andre
 * 
 * Created on 19 de noviembre de 2024, 16:09
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PedidoEventual.h"

PedidoEventual::PedidoEventual() {
    flete = 0;
}

void PedidoEventual::lee(ifstream& arch, int codigo) {
    arch >> flete;
    arch.get();
    Pedido::lee(arch,codigo);
}


