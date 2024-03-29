

/* 
 * File:   Funciones.h
 * Author: andre
 *
 * Created on 24 de marzo de 2024, 14:24
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
void operator*=(struct Persona &, double);
//void operator <<(ostream &, const struct Persona &);
ostream & operator<<(ostream &, const struct Persona &);
void operator >>(ifstream &, struct Persona &);
//istream & operator >> (istream &in, struct Persona &p);
//istream & operator >>(ifstream &arch, struct Persona &p);
#endif /* FUNCIONES_H */

