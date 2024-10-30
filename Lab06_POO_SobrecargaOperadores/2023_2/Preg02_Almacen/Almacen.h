/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Almacen.h
 * Author: alulab14
 *
 * Created on 25 de octubre de 2024, 05:12 PM
 */

#ifndef ALMACEN_H
#define ALMACEN_H
#include "Cliente.h"
#include "Producto.h"
class Almacen {
public:
    Almacen();
    virtual ~Almacen();
    void SetCantidad_productos(int cantidad_productos);
    int GetCantidad_productos() const;
    void SetCantidad_clientes(int cantidad_clientes);
    int GetCantidad_clientes() const;
    
    void cargar_clientes();
    void cargar_productos();
    void cargar_pedidos();
    void mostrar_datos();
    int buscarPosProducto(const class Producto *arrProd,char *codProdPed);
    int buscarPosCliente(const class Cliente *arrClie,int dniPed);
private:
    class Cliente arreglo_clientes[200];
    int cantidad_clientes;
    class Producto arreglo_productos[200];
    int cantidad_productos;
};
void imprimirLineas(ofstream &arch,int cant,char car);

#endif /* ALMACEN_H */

