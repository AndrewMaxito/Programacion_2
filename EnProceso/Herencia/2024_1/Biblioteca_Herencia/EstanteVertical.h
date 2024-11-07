
/* 
 * File:   EstanteVertical.h
 * Author: andre
 *
 * Created on 7 de noviembre de 2024, 12:02
 */

#ifndef ESTANTEVERTICAL_H
#define ESTANTEVERTICAL_H

#include "Enciclopedia.h"
#include "Estantes.h"

class EstanteVertical : public Estantes {
public:
    EstanteVertical();
    void SetCantidad_novelas(int cantidad_novelas);
    int GetCantidad_novelas() const;
    //
    void leerDatosEstaVerti(ifstream &arch);

private:
    class Enciclopedia enciclopedias[50];
    int cantidad_novelas;
};

#endif /* ESTANTEVERTICAL_H */

