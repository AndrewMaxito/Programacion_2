/* 
 * File:   hijo1.h
 * Author: andre
 *
 * Created on 20 de noviembre de 2024, 09:46 PM
 */

#ifndef HIJO1_H
#define HIJO1_H

#include "Padre.h"

class hijo1 : public Padre {
public:
    hijo1();
    hijo1(const hijo1& orig);
    virtual ~hijo1();
    void leer(ifstream& arch) override;
    void setNumerohijo1(int numerohijo1);
    int getNumerohijo1() const;
    void setCarHijo1(const char* cad);
    void getCarHijo1(char *cad) const;

private:
    char *carHijo1;
    int numerohijo1;
};

#endif /* HIJO1_H */

