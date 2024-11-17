
/* 
 * File:   Pedido.h
 * Author: andre
 *
 * Created on 12 de noviembre de 2024, 14:42
 */

#ifndef PEDIDO_H
#define PEDIDO_H

#include <fstream>
using namespace std;

class Pedido {
public:
    Pedido();
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
private:
    int codigo;
    int cantidad;
    int dni;
    int fecha;
    double total;
};

bool operator >> (ifstream &arch,Pedido &ped);
#endif /* PEDIDO_H */

