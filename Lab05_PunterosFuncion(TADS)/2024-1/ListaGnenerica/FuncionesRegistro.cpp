#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

void *leeregistro(ifstream &arch) {
    int *numPed, *dni, numBasura;
    char *codigo, buff[8], c;
    void **registro;

    arch >> numBasura;
    if (arch.eof()) return nullptr;
    arch.get();
    numPed = new int(numBasura);
    dni = new int;
    codigo = new char [8];
    arch >> *dni >> c >>buff;
    strcpy(codigo, buff);
    registro = new void *[3];
    registro[0] = numPed;
    registro[1] = dni;
    registro[2] = codigo;
    return registro;
}

void imprimeregistro(ofstream &arch, void *dato) {
    void **datosRegis = (void **) (dato);
    int *numPed = (int *) (datosRegis[0]);
    int *dni = (int *) (datosRegis[1]);
    char *codigo = (char *) (datosRegis[2]);
    arch << left << setw(15) << *numPed << setw(15) << *dni << codigo << endl;
}


int cmpregistro(void *dato1,void *dato2){
    void **registro1 = (void **)dato1, **registro2 = (void **)dato2;
    int *num1=(int *)(registro1[0]),*num2=(int *)(registro2[0]);
    return (*num1 - *num2);
} 




