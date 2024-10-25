

/* 
 * File:   Almacen.h
 * Author: andre
 *
 * Created on 22 de mayo de 2024, 19:07
 */

#ifndef ALMACEN_H
#define ALMACEN_H
#include <fstream>
using namespace std;

#include "Cliente.h"
#include "Producto.h"


class Almacen {
private:
    class Cliente arreglo_clientes[200];
    int cantidad_clientes;
    class Producto arreglo_producto[300];
    int cantidad_productos;

public:
    Almacen();
    void SetCantidad_productos(int cantidad_productos);
    int GetCantidad_productos() const;
    void SetCantidad_clientes(int cantidad_clientes);
    int GetCantidad_clientes() const;
    void cargar_clientes();
    void cargar_producto();
    void cargar_pedidos();
    void mostrar_datos();
};
void imprimirLineas(ofstream &arch,int ,char);
#endif /* ALMACEN_H */

