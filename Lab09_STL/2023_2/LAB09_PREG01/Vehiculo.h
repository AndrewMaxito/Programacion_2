
/* 
 * File:   Vehiculo.h
 * Author: andre
 *
 * Created on 27 de noviembre de 2024, 09:00 PM
 */

#ifndef VEHICULO_H
#define VEHICULO_H
#include <fstream>

#include "NPedido.h"
using namespace std;
class Vehiculo {
public:
    Vehiculo();
    Vehiculo(const Vehiculo& orig);
    virtual ~Vehiculo();
    void SetActCarga(double actCarga);
    double GetActCarga() const;
    void SetMaxCarga(double maxCarga);
    double GetMaxCarga() const;
    void SetPlaca(const char* cad);
    void GetPlaca(char* cad) const;
    void SetCliente(int cliente);
    int GetCliente() const;
    //
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch)const ;
    virtual void cargaDeposito(NPedido &ped);
private:
    int cliente;
    char* placa;
    double maxCarga;
    double actCarga;
};

#endif /* VEHICULO_H */

