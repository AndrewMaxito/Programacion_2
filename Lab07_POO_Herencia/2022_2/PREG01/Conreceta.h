
/* 
 * File:   Conreceta.h
 * Author: andre
 *
 * Created on 7 de Nov de 2024, 16:33
 */

#ifndef CONRECETA_H
#define CONRECETA_H
#include <fstream>
using namespace std;
#include "Medicamentos.h"

class Conreceta : public Medicamentos {
private:
    //Datos con receta
    int codmed;
    char* especialidad;


public:
    Conreceta();
    virtual ~Conreceta();
    void setEspecialidad(const char* cad);
    void getEspecialidad(char *cad) const;
    void setCodmed(int codmed);
    int getCodmed() const;
    //
    void cargarDatosConRec(int codigoMed, char *especiali, int codigoMedicamneto,
            int cantMedi, int fecha, ifstream & archMedica);







};

#endif /* CONRECETA_H */

