/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   BibliotecaEstatica.h
 * Author: andre
 *
 * Created on 4 de abril de 2024, 20:28
 */

#ifndef BIBLIOTECAESTATICA_H
#define BIBLIOTECAESTATICA_H

#include <fstream>
using namespace std;

bool operator >> (ifstream &archCliente,struct Cliente &cliente);
bool operator >> (ifstream &archPro,struct Producto &prod);
bool operator >> (ifstream &archPedi,struct Pedido &pedi);


void operator += (struct Cliente *arrCli,const struct Pedido &Ped);
bool operator += (struct Producto *arrPro,const struct Pedido &Ped);


void operator << (ofstream &arch,const struct Cliente &cliente);
void operator << (ofstream &arch,const struct Producto &Pro);




#endif /* BIBLIOTECAESTATICA_H */

