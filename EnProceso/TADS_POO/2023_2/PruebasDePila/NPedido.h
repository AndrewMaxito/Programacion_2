
/* 
 * File:   NPedido.h
 * Author: andre
 *
 * Created on 20 de noviembre de 2024, 09:00 PM
 */

#ifndef NPEDIDO_H
#define NPEDIDO_H

class NPedido {
public:
    NPedido();
    NPedido(const NPedido& orig);
    virtual ~NPedido();
    friend class Vehiculo;
private:
    char *codigo;
    int cantidad;
    double peso;
    NPedido *sig;
};

#endif /* NPEDIDO_H */

