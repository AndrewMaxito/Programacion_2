
/* 
 * File:   Nodo.cpp
 * Author: andre
 * 
 * Created on 19 de noviembre de 2024, 16:11
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Nodo.h"

Nodo::Nodo() {
    ped = nullptr;
    sig = nullptr;
    ant = nullptr;
}

