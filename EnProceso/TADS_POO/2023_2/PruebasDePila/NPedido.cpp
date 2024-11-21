
/* 
 * File:   NPedido.cpp
 * Author: andre
 * 
 * Created on 20 de noviembre de 2024, 09:00 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "NPedido.h"

NPedido::NPedido() {
    codigo = nullptr;
    cantidad = 0;
    peso = 0.0;
    sig = nullptr;
}

NPedido::NPedido(const NPedido& orig) {
}

NPedido::~NPedido() {
    //if (codigo != nullptr)delete[] codigo;
}

