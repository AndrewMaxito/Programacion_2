#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

void *leenum(ifstream &arch){
    void **datosReg;
    int *numero,num;
    
    arch >> num;
    if (arch.eof())return nullptr;
    numero = new int ;
    *numero = num;
    datosReg = new void *[1];
    datosReg[0] = numero;
    return datosReg;
}

void imprimenum(ofstream &arch,void *dato){
    void **datosRegis = (void **)(dato); 
    int *numero = (int *)(datosRegis[0]);
    arch << *numero <<endl;
}


int cmpnum(void *dato1,void *dato2){
    void **registro1 = (void **)dato1, **registro2 = (void **)dato2;
    int *num1=(int *)(registro1[0]),*num2=(int *)(registro2[0]);
    return (*num1 - *num2);
}