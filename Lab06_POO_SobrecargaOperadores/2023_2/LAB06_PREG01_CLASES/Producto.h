
/* 
 * File:   Producto.h
 * Author: andre
 *
 * Created on 22 de mayo de 2024, 19:00
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <fstream>
using namespace std;

class Producto {
private:
    char* codigo;
    char* descripcion;
    double precio;
    int stock;
    int clientes_servidos[200];
    int clientes_no_servidos[200];
    int cantidad_clientes_servidos;
    int cantidad_clientes_no_servidos;
public:
    Producto();
    virtual ~Producto();
    void SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos);
    int GetCantidad_clientes_no_servidos() const;
    void SetCantidad_clientes_servidos(int cantidad_clientes_servidos);
    int GetCantidad_clientes_servidos() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetDescripcion(const char* cad);
    void GetDescripcion(char *cad) const;
    void SetCodigo(const char* cad);
    void GetCodigo(char *cad) const;
    bool operator += (const class Pedido& ped );
    int  metodoGAA(int i)const ;
    int  metodoRAAA(int i)const ;
    
};
void operator<<(ostream &os, const Producto &producto);
bool operator>>(ifstream&arch, class Producto &pro);
#endif /* PRODUCTO_H */

