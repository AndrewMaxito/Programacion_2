

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
    
    //Pregunta 1
    crearLista(pedidos1,leeNum,"RegistroNum1.txt");
    imprimeLista(pedidos1,imprimeNum,"RepNum1.txt");
    crearLista(pedidos2,leeNum,"RegistroNum2.txt");
    imprimeLista(pedidos2,imprimeNum,"RepNum2.txt");
    
    //Pregunta 2
    combinarLista(pedidos1,pedidos2,pedidosFinal,cmpNum);
    imprimeLista(pedidosFinal,imprimeNum,"RepNumFinal.txt");
    
    //Pregunta 3
    crearLista(pedidos1,leeRegistro,"Pedidos31.csv");
    imprimeLista(pedidos1,imprimeRegistro,"RepReg1.txt");
    crearLista(pedidos2,leeRegistro,"Pedidos32.csv");
    imprimeLista(pedidos2,imprimeRegistro,"RepReg2.txt");
    combinarLista(pedidos1,pedidos2,pedidosFinal,cmpRegistro);
    imprimeLista(pedidosFinal,imprimeRegistro,"RepRegFinal.txt");
    
    return 0;
}

