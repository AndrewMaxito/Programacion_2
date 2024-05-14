/* 
 * Proyecto: Pregunta01
 * Archivo:  Pregunta01Examen01PunterosMultiples.h
 * Autor:    J. Miguel Guanira E.
 *
 * Created on 6 de octubre de 2023, 09:31 PM
 */

#ifndef PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H
#define PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H

void cargarPedidos (int **&, char **&, const char *);
void pruebaDeCargaDePedidos (int **, char **, const char *);
int * leeRegistro(ifstream &arch);
void aumentarEspacios(int **&, char **&, int &, int &);
void imprimePedido(ofstream &,int *,char *); 

#endif /* PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H */

