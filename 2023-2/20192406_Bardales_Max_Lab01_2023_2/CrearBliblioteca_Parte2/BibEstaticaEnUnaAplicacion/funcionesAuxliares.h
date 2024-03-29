
/* 
 * File:   funcionesAuxliares.h
 * Author: andre
 *
 * Created on 28 de marzo de 2024, 19:36
 */

#ifndef FUNCIONESAUXLIARES_H
#define FUNCIONESAUXLIARES_H

void leerClientes(struct Cliente *clientes,const char *nombArch);
void leerProductos(struct Producto *productos,const char *nombArch);
void completarClientesProductos(struct Cliente *clientes,
        struct Producto *productos,const char *nombArch);
void elaborarReporte(struct Cliente *clientes,struct Producto *productos,const char *nombArch);

#endif /* FUNCIONESAUXLIARES_H */

