/* 
 * File:   main.cpp
 * Author: Andrew Max
 *
 * Created on 21 de setiembre de 2024, 19:52
 */

#include <iomanip>
#include <iostream>

using namespace std;
#include "PunterosGenericos.h"
#include "MuestraPunteroGenerico.h"



int main(int argc, char** argv) {
    void *clientes,*reserva;
    
    cargaClientes(clientes);
    creaReserva(reserva);
    cargaRerserva(clientes,reserva);
    reportefinal(reserva);

    return 0;
}

