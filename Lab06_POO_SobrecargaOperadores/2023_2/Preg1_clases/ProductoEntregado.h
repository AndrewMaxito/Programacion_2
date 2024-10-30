/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProductoEntregado.h
 * Author: alulab14
 *
 * Created on 25 de octubre de 2024, 04:25 PM
 */

#ifndef PRODUCTOENTREGADO_H
#define PRODUCTOENTREGADO_H

class ProductoEntregado {
public:
    ProductoEntregado();
    virtual ~ProductoEntregado();
    void SetPrecio(double precio);
    double GetPrecio() const;
    
    void SetCodigo(const char* cad);
    void GetCodigo(char *cad) const;
private:
    char *codigo;
    double precio;
};

#endif /* PRODUCTOENTREGADO_H */

