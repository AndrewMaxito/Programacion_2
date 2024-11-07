
/* 
 * File:   Sinreceta.h
 * Author: andre
 *
 * Created on 7 de Nov de 2024, 16:33
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
    void cargarDatosSinRec(int dni,char* nombreCliente,
                            int codigoMedicamneto, int cantMedi,int  fecha,ifstream &archMedica);

};

#endif /* SINRECETA_H */

