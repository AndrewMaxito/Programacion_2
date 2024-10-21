/* 
 * File:   PilaConEnteros.cpp
 * Author: andre
 * 
 * Created on 19 de octubre de 2024, 18:40
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
#include "PilaConEnteros.h"



void *leeNumero(ifstream &arch){
    double buffNum;
    arch >> buffNum;
    if (arch.eof()) return nullptr;
    double *numero = new double (buffNum);
    return numero;
}

double calculaNumero(void *datos){
    
    
    
    
}