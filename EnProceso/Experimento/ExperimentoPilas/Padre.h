

/* 
 * File:   Padre.h
 * Author: andre
 *
 * Created on 20 de noviembre de 2024, 09:45 PM
 */

#ifndef PADRE_H
#define PADRE_H

class Padre {
public:
    Padre();
    Padre(const Padre& orig);
    virtual ~Padre();
private:
    int codigoPadre;
    char *nombrePadre;
};

#endif /* PADRE_H */

