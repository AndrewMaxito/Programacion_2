/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bibliotecaEstatica.h
 * Author: andre
 *
 * Created on 5 de septiembre de 2024, 01:05 PM
 */

#ifndef BIBLIOTECAESTATICA_H
#define BIBLIOTECAESTATICA_H
#include <fstream>
using namespace std;

bool operator>>(ifstream &arch, struct Libro &lib);
bool operator>>(ifstream &arch, struct Cliente &cli);


bool operator>>(struct LibroSolicitado &lib, struct Libro *arrLibros);
bool operator >> (struct Cliente &cli,struct LibroSolicitado &libSol);
void operator ++ (struct Cliente &cli);

void operator << (ofstream &arch,struct Libro &lib);
void operator<<(ofstream &arch, struct Cliente &cli);

#endif /* BIBLIOTECAESTATICA_H */
