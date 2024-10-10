

/* 
 * File:   FuncionesEnteras.cpp
 * Author: andre
 * 
 * Created on 9 de octubre de 2024, 12:07
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "FuncionesEnteras.h"



void *leeNum(ifstream &arch){
    int num;
    arch >> num;
    if (arch.eof()) return nullptr;
    int *numero = new int (num);
    return numero;
}


void imprimeNum(ofstream &arch,void *dato){
    int *numero = (int *)dato;
    arch << *numero<<endl;
}

int cmpNum(void *a,void *b){
    if (a == nullptr) return 1;
    if (b == nullptr) return -1;
    
    void **datosA = (void **)a;
    void **datosB = (void **)b;
    
    int *valorA = (int *)(datosA[0]);
    int *valorB = (int *)(datosB[0]);
    
    return (*valorA)-(*valorB);
}