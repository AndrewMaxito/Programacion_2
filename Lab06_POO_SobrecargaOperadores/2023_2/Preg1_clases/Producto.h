/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.h
 * Author: alulab14
 *
 * Created on 25 de octubre de 2024, 04:57 PM
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <fstream>
using namespace std;
#include "Pedido.h"
using namespace std;
class Producto {
public:
    Producto();
    
    virtual ~Producto();
    void SetCantidad_no_clientes_servidos(int cantidad_no_clientes_servidos);
    int GetCantidad_no_clientes_servidos() const;
    void SetCantidad_clientes_servidos(int cantidad_clientes_servidos);
    int GetCantidad_clientes_servidos() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    
    void SetDescripcion(const char* cad);
    void GetDescripcion(char *cad) const;
    void SetCodigo(const char* cad) ;
    void GetCodigo(char *cad) const;
    
    bool operator += (class Pedido &);
    
    
    int metodoGetDniAtendido(int )const ;
    int metodoGetDniNoAtendidos(int pos)const;
private:
    char *codigo;
    char *descripcion;
    double precio;
    int stock;
    int clientes_servidos[100];
    int clientes_no_servidos[100];
    int cantidad_clientes_servidos;
    int cantidad_no_clientes_servidos;
};
bool operator >> (ifstream &arch,class Producto &prod);
void operator << (ofstream &arch, const class Producto &prod);
#endif /* PRODUCTO_H */

