/* 
 * File:   ColaPrioridadGenerica.h
 * Author: andre
 *
 * Created on 22 de octubre de 2024, 16:58
 */

#ifndef COLAPRIORIDADGENERICA_H
#define COLAPRIORIDADGENERICA_H
void cargaRanking(void *&ranking,void *(*creaRegistro)(void *),void *ventas);
void *generarCola();
void encola(void *cola, void *registro, int rank) ;
bool colaVacia(void *cola) ;
#endif /* COLAPRIORIDADGENERICA_H */
