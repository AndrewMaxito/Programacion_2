
/* 
 * File:   funcionesAuxiliares.h
 * Author: andre
 *
 * Created on 22 de mayo de 2024, 10:45
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>
using namespace std;


void operator >> (ifstream &arch,class alumno &alu);
void operator >> (ifstream &arch,class alumnonota &notAlu);
void operator<<(ofstream &arch, const class alumno &alu);

#endif /* FUNCIONESAUXILIARES_H */

