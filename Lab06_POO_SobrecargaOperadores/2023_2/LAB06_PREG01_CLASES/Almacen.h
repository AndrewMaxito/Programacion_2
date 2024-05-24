

/* 
 * File:   Almacen.h
 * Author: andre
 *
 * Created on 22 de mayo de 2024, 19:07
 */

#ifndef ALMACEN_H
#define ALMACEN_H

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
    Almacen(const Almacen& orig);
    virtual ~Almacen();

};

#endif /* ALMACEN_H */

