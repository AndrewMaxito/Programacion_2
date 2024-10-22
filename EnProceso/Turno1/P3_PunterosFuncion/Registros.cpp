/* 
 * File:   Registros.cpp
 * Author: andre
 * 
 * Created on 22 de octubre de 2024, 16:59
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Registros.h"



void *creaRegistro(void *venta){
    void **datos = (void **)venta;
    
    void **registroDat = new void *[5];
    registroDat[0] = datos[0];
    registroDat[1] = datos[1];
    registroDat[2] = datos[2];
    registroDat[3] = datos[7];
    registroDat[4] = datos[3];
    return registroDat;
}