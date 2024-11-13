

/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 12 de noviembre de 2024, 14:07
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Procesa.h"



int main(int argc, char** argv) {
    Procesa pro;
    pro.carga();
    pro.actualiza();
    pro.muestra();
    
    
    return 0;
}

