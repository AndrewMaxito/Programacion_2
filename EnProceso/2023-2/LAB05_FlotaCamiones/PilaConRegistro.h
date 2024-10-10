

/* 
 * File:   PilaConRegistro.h
 * Author: andre
 *
 * Created on 30 de abril de 2024, 22:16
 */

#ifndef PILACONREGISTRO_H
#define PILACONREGISTRO_H
void *leeregistro(ifstream &arch);
char *leerCadenaExacta(ifstream &arch,char deli);
double calcularegistro(void *reg);
int cmpregistro(const void *izq, const void *der);
void imprimeregistro(ofstream &arch, void *reg);
#endif /* PILACONREGISTRO_H */

