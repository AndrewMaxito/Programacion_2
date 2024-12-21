

/* 
 * File:   sobreCargaOpera.h
 * Author: andre
 *
 * Created on 28 de marzo de 2024, 13:34
 */

#ifndef SOBRECARGAOPERA_H
#define SOBRECARGAOPERA_H
#include <fstream>
using namespace std;
bool operator >>(ifstream &arch, struct Cliente &cli); 
bool operator >>(ifstream &arch, struct Pedido &pedido);
bool operator >>(ifstream &arch, struct Producto &producto);
void operator +=(struct Cliente *arrClientes,const struct Pedido &ped);
bool operator +=(struct Producto *arrProd,struct Pedido &ped);
void operator <<(ofstream &arch, const struct Cliente &cli);
void operator <<(ofstream &arch, const struct Producto &prod);

#endif /* SOBRECARGAOPERA_H */

