
/* 
 * File:   BibliotecaEstatica.h
 * Author: andre
 *
 * Created on 26 de abril de 2024, 13:41
 */

#ifndef BIBLIOTECAESTATICA_H
#define BIBLIOTECAESTATICA_H
#include <fstream>
using namespace std;
bool operator >> (ifstream &arch,struct Libro &libro);
bool operator >> (ifstream &arch,struct Cliente &cliente);
bool operator>>(struct LibroSolicitado &libroPedido, struct Libro *arrLibro);
bool operator << (struct Cliente &cliente, struct LibroSolicitado &libroPedido);
void operator ++(struct Cliente &cliente);
void operator << (ofstream &archRepLib , struct Libro &libro);
void operator<<(ofstream &archRepCli,struct Cliente &cliente);
#endif /* BIBLIOTECAESTATICA_H */

