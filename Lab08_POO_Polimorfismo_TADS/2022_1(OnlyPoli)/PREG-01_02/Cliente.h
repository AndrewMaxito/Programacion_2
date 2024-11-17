

/* 
 * File:   Cliente.h
 * Author: andre
 *
 * Created on 12 de noviembre de 2024, 14:11
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include <fstream>
using namespace std;


class Cliente {
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetTotalPed(double totalPed);
    double GetTotalPed() const;
    void SetCantPed(int cantPed);
    int GetCantPed() const;
    void SetNombre(const char* cad);
    void GetNombre(char *cad) const;
    void SetCategoria(char categoria);
    char GetCategoria() const;
    void SetDni(int dni);
    int GetDni() const;
    //
    virtual void lee(ifstream &arch,char catego);
    virtual void imprime(ofstream &arch, double descuento, double flete);
    virtual void calcula(double monto)=0;

private:
    int dni;
    char categoria;
    char *nombre;
    int cantPed;
    double totalPed;
};

#endif /* CLIENTE_H */

