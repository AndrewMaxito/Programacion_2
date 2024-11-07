

/* 
 * File:   EstanteHorizontal.h
 * Author: andre
 *
 * Created on 7 de noviembre de 2024, 12:08
 */

#ifndef ESTANTEHORIZONTAL_H
#define ESTANTEHORIZONTAL_H

#include "Novela.h"
#include "Estantes.h"


class EstanteHorizontal : public Estantes {
public:
    EstanteHorizontal();
    void SetCantidad_novelas(int cantidad_novelas);
    int GetCantidad_novelas() const;
    //
    void leerDatosEstaHori(ifstream &arch);
    
private:
    Novela novelas[100];
    int cantidad_novelas;

};

#endif /* ESTANTEHORIZONTAL_H */

