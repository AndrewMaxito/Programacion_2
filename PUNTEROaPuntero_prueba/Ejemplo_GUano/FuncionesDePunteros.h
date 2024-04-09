#ifndef FUNCIONESDEPUNTEROS_H
#define FUNCIONESDEPUNTEROS_H
#include <fstream>
using namespace std;

void leerNombres(char **&, int &, const char *);
void ordenar(char **, int, int);
void imprimir(char **, int, const char *);
char* leeCadena(ifstream &);
void cambiar(char**, int, int);

void ordenarNum(int *arr,int ,int );
void cambiarNum(int *arr, int i, int k);

#endif /* FUNCIONESDEPUNTEROS_H */