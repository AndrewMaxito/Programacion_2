
/* 
 * File:   PunterosGenericos.h
 * Author: andre
 *
 * Created on 21 de abril de 2024, 15:03
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

void leerUsurarios(void *&usuarios);
void *leerUsuario(ifstream &arch);
char *leerCadenaExacta(ifstream &arch,char deli);
void imprimirUsuarios(void *usuarios);
void imprimeUsuario(void *registro, ofstream &arch);



#endif /* PUNTEROSGENERICOS_H */

