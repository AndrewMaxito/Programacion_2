

/* 
 * File:   Escala.h
 * Author: andre
 *
 * Created on 5 de noviembre de 2024, 16:25
 */

#ifndef ESCALA_H
#define ESCALA_H

class Escala {
public:
    Escala();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
private:
    int codigo;
    double precio;

};

#endif /* ESCALA_H */

