
/* 
 * File:   funcionesRegistro.cpp
 * Author: andre
 * 
 * Created on 24 de octubre de 2024, 16:59
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "funcionesRegistro.h"
//AP-500,CHORIZOS COCKTAIL,12.90,APERITIVO
    //AP-410,ANTICUCHO,12.90,APERITIVO


void *leerRegistro(ifstream &arch ){
    char *codigoPlato,buff[200];
    codigoPlato = leerCadenaExacta(arch,',');
    if (codigoPlato == nullptr) return nullptr;
    //caso que la cantidad de platos sea fija (o me den el stock)
    arch.getline(buff,200); //hasta el salto de linea solo necesito el codigo
    int *stock = new int (0);
    
    void **registro = new void *[2];
    registro[0] = new void *[2];
    
    void **datoPlato = (void **)(registro[0]);
    datoPlato[0] = codigoPlato;
    datoPlato[1] = stock;
    registro[1] = new void *[100]{};
    return registro;
}
char* leerCadenaExacta(ifstream &arch,char deli){
    char buff[100],*ptr;
    arch.getline(buff,100,',');
    if (arch.eof()) return nullptr;
    ptr = new char [strlen(buff)+1];
    strcpy(ptr,buff);
    return ptr;
}