/* 
 * File:   Padre.h
 * Author: andre
 *
 * Created on 20 de noviembre de 2024, 09:45 PM
 */

#ifndef PADRE_H
#define PADRE_H
#include <fstream>
using namespace std;

class Padre {
public:
    Padre();
    Padre(const Padre& orig);
    virtual ~Padre();
    //
    virtual void leer(ifstream &arch);
    void setNombrePadre(const char* cad);
    void getNombrePadre(char *cad) const;
    void setCodigoPadre(int codigoPadre);
    int getCodigoPadre() const;
    //
    //Sobrecargar el igual para hacer una copia
private:
    int codigoPadre;
    char *nombrePadre;
};

#endif /* PADRE_H */

