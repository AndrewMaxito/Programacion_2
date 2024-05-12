/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 11 de mayo de 2024, 11:32
 */

#include <iostream>
#include <iomanip>

#include "BibliotecaGenerica.h"
#include "FuncionesEnteras.h"
#include "FuncionesRegistro.h"

using namespace std;

int main(int argc, char** argv) {
    void *pedidos1,*pedidos2,*pedidiosFinal;
    
    
//    Pregunta 1 
    
    crealista(pedidos1,leenum,"RegistroNum1.txt");
    imprimelista(pedidos1,imprimenum,"Repnum1.txt");
    crealista(pedidos2,leenum,"RegistroNum2.txt");
    imprimelista(pedidos2,imprimenum,"Repnum2.txt");
    
//    Pregunta 2 
    
    combinalista(pedidos1,pedidos2,pedidiosFinal,cmpnum);
    imprimelista(pedidiosFinal,imprimenum,"RepnumFinal.txt");
    
//    Pregunta 3
    
    
    crealista(pedidos1,leeregistro,"Pedidos31.csv");
    imprimelista(pedidos1,imprimeregistro,"Repreg1.txt");
    crealista(pedidos2,leeregistro,"Pedidos32.csv");
    imprimelista(pedidos2,imprimeregistro,"Repreg2.txt");
    combinalista(pedidos1,pedidos2,pedidiosFinal,cmpregistro);
    imprimelista(pedidiosFinal,imprimeregistro,"RepredFinal.txt");
    
    return 0;
}

