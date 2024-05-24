
/* 
 * File:   Cliente.h
 * Author: andre
 *
 * Created on 22 de mayo de 2024, 18:55
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include <fstream>
using namespace std;
#include "ProductoEntregado.h"

class Cliente {
private:
    int dni;
    char* nombre;
    int telefono;
    class ProductoEntregado productos_entregados[300];
    int cantidad_productos_entregados;
    double monto_total;
public:
    Cliente();
    virtual ~Cliente();
    void SetMonto_total(double monto_total);
    double GetMonto_total() const;
    void SetCantidad_productos_entregados(int cantidad_productos_entregados);
    int GetCantidad_productos_entregados() const;
    void SetTelefono(int telefono);
    int GetTelefono() const;
    void SetNombre(const char* cad);
    void GetNombre(char *cad) const ;
    void SetDni(int dni);
    int GetDni() const;
    void metodo(int i,char*cad)const;
    //Sobrecarga
    void operator += (const class Pedido& ped);
    
};
void operator << (ofstream&arch,const class Cliente &cli);
bool operator >> (ifstream&arch,class Cliente &cli);

#endif /* CLIENTE_H */

