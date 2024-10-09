
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

void *leenumero(ifstream &arch) {
    int dato;
    arch >> dato;
    if (arch.eof()) return nullptr;
    return new double (dato);
}

double calculanumero(void *reg) {
    double *dato = (double *) reg; //repasarlo----------------------------
    return *dato;
}

int cmpnumero(const void *izq, const void *der) {
    void **auxIzq = (void **) izq, **auxDer = (void **) der; //no entiendooooooooooo

    void **pilaIzq = (void **) (auxIzq[0]), **pilaDer = (void **) (auxDer[0]);

    double *pesoIzq = (double *) (pilaIzq[1]), *pesoDer = (double *) (pilaDer[1]);
    return (*pesoDer - *pesoIzq );
}



void imprimenumero(ofstream &arch,void *reg){
    double *dato = (double *)reg;
    arch << *dato <<endl;
}