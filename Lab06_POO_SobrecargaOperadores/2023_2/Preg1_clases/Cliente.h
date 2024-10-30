/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.h
 * Author: alulab14
 *
 * Created on 25 de octubre de 2024, 04:42 PM
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include <fstream>
using namespace std;
#include "ProductoEntregado.h"
#include "Pedido.h"

class Cliente {
public:
    Cliente();
    
    virtual ~Cliente();
    void SetMonto_total(double monto_total);
    double GetMonto_total() const;
    void SetCantidad_productos_entregados(int cantidad_productos_entregados);
    int GetCantidad_productos_entregados() const;
    void SetTelefono(int telefono);
    int GetTelefono() const;
    void SetNombre(const char* cad) ;
    void GetNombre(char *cad) const ;
    void SetDni(int dni);
    int GetDni() const;
    
    void operator += (const class Pedido &);
    
    void metodoObtennerProdEntregados(int pos,char *cad)const ;//imporante poner el const al final 
private:
    int dni;
    char* nombre;
    int telefono;
    class ProductoEntregado productos_entregados[300];
    int cantidad_productos_entregados;
    double monto_total;
};
bool operator >> (ifstream &arch, class Cliente &cli);
void operator << (ofstream &arch, const class Cliente &cli);

#endif /* CLIENTE_H */

