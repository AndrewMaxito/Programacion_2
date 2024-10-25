
/* 
 * File:   ProductoEntregado.h
 * Author: andre
 *
 * Created on 22 de mayo de 2024, 18:53
 */

#ifndef PRODUCTOENTREGADO_H
#define PRODUCTOENTREGADO_H

class ProductoEntregado {
private:
    char* codigo;
    double precio;
public:
    ProductoEntregado();
    virtual ~ProductoEntregado();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(const char* cad);
    void GetCodigo(char *cad) const ;
};

#endif /* PRODUCTOENTREGADO_H */

