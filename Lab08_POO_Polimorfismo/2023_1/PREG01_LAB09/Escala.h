
/* 
 * File:   Escala.h
 * Author: andre
 *
 * Created on 11 de junio de 2024, 18:18
 */

#ifndef ESCALA_H
#define ESCALA_H

class Escala {
private:
    int codigo;
    double precio;

public:
    Escala();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;

};

#endif /* ESCALA_H */

