

/* 
 * File:   Pedido.h
 * Author: andre
 *
 * Created on 19 de noviembre de 2024, 15:53
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <fstream>
using namespace std;
class Pedido {
public:
    Pedido();
    virtual ~Pedido();
    void SetNombre(const char* cad);
    void GetNombre(char *cad) const;
    void SetCodigo(int codigo) ;
    int GetCodigo() const;
    //
    virtual void lee(ifstream &arch,int codigo);
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;

private:
    int codigo;
    char *nombre;
    int cantidad;
    int dni;
    int fecha;
    double total;

};

#endif /* PEDIDO_H */

