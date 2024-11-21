
/* 
 * File:   hijo2.h
 * Author: andre
 *
 * Created on 20 de noviembre de 2024, 09:46 PM
 */

#ifndef HIJO2_H
#define HIJO2_H

#include "Padre.h"


class hijo2: public Padre {
public:
    hijo2();
    hijo2(const hijo2& orig);
    virtual ~hijo2();
private:
    char *carHijo2;
    int numerohijo2;
};

#endif /* HIJO2_H */

