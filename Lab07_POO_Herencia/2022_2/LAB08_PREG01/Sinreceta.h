
/* 
 * File:   Sinreceta.h
 * Author: andre
 *
 * Created on 28 de mayo de 2024, 12:41
 */

#ifndef SINRECETA_H
#define SINRECETA_H

#include "Medicamentos.h"


class Sinreceta: public Medicamentos {
private:
    //Datos del paciente
    int dni;
    char* nombre;
public:
    Sinreceta();
    virtual ~Sinreceta();
    void SetNombreS(const char* cad) ;
    void GetNombreS(char *cad) const;
    void SetDni(int dni);
    int GetDni() const;

};

#endif /* SINRECETA_H */

