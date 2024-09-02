

/* 
 * File:   Boleta.h
 * Author: andre
 *
 * Created on 11 de junio de 2024, 18:20
 */

#ifndef BOLETA_H
#define BOLETA_H
#include <fstream>
using namespace std;
#include "Alumno.h"


class Boleta {
private:
    class Alumno* pboleta;

public:
    Boleta();
    virtual ~Boleta();
    void leer(ifstream &arch);
    bool existe() const;
    void mostrar(ofstream &arch);
    
    
};
void operator >> (ifstream &arch, class Boleta &boleta );


#endif /* BOLETA_H */

