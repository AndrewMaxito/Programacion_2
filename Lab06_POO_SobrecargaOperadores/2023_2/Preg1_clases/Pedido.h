/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.h
 * Author: alulab14
 *
 * Created on 25 de octubre de 2024, 05:08 PM
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <fstream>
using namespace std;

class Pedido {
public:
    Pedido();
    virtual ~Pedido();
    void SetPrecio_producto(double precio_producto);
    double GetPrecio_producto() const;
    void SetDni_cliente(int dni_cliente);
    int GetDni_cliente() const;
    void SetCodigo(const char* cad) ;
    void GetCodigo(char *cad) const ;
    
    
private:
    char *codigo;
    int dni_cliente;
    double precio_producto;
};

bool operator>>(ifstream &arch, class Pedido &pedi);

#endif /* PEDIDO_H */

