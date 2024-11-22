/* 
 * File:   ClDatos.h
 * Author: andre
 *
 * Created on 20 de noviembre de 2024, 09:42 PM
 */

#ifndef CLDATOS_H
#define CLDATOS_H
#include <fstream>
using namespace std;
#include "Padre.h"

class ClDatos {
public:
    ClDatos();
    ClDatos(const ClDatos& orig);
    virtual ~ClDatos();
    //
    void operator=(const ClDatos &datos);
    void SetNombre(const char* cad);
    void GetNombre(char* cad) const;
    void SetCodigoDato(int codigoDato);
    int GetCodigoDato() const;
    //
    void cargarDatoObj(ifstream &arch);
private:
    int codigoDato;
    char *nombreDato;
    Padre *objPadre;
};

#endif /* CLDATOS_H */

