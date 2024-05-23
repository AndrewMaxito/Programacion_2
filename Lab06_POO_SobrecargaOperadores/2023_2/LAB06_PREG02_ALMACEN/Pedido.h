
/* 
 * File:   Pedido.h
 * Author: andre
 *
 * Created on 22 de mayo de 2024, 19:04
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <fstream>
using namespace std;

class Pedido {
private:
    char* codigo;
    int dni_cliente;
    double precio_producto;
public:
    Pedido();
    virtual ~Pedido();
    void SetPrecio_producto(double precio_producto);
    double GetPrecio_producto() const;
    void SetDni_cliente(int dni_cliente);
    int GetDni_cliente() const;
    void SetCodigo(const char* cad);
    void GetCodigo(char *cad) const;

};
bool operator>>(ifstream&arch, class Pedido &ped);
#endif /* PEDIDO_H */

