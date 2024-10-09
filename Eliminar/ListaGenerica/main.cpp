

/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 9 de octubre de 2024, 12:04
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "BibliotecaGenerica.h"
#include "FuncionesEnteras.h"
#include "FuncionesRegistro.h"

int main(int argc, char** argv) {
    void *pedidos1,*pedidos2,*pedidosFinal;
    
    crearLista(pedidos1,leeNum,"RegistroNum1.txt");
    imprimeLista(pedidos1,imprimeNum,"RepNum1.txt");
    crearLista(pedidos2,leeNum,"RegistroNum2.txt");
    imprimeLista(pedidos2,imprimeNum,"RepNum2.txt");
    
    combinarLista(pedidos1,pedidos2,pedidosFinal,cmpNum);
    imprimeLista(pedidosFinal,imprimeNum,"RepNumFinal.txt");

    return 0;
}

