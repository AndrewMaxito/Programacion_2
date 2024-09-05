/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionesAux.h
 * Author: andre
 *
 * Created on 5 de septiembre de 2024, 02:20 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H

void cargarPedido(ifstream &archPedido,struct Libro *arrLibro,struct Cliente *arrClientes);
int buscarPosCliente(int dniCliente,struct Cliente *arrClientes);
#endif /* FUNCIONESAUX_H */
