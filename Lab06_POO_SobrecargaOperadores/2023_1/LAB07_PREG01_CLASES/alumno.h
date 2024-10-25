

/* 
 * File:   alumno.h
 * Author: andre
 *
 * Created on 22 de mayo de 2024, 10:21
 */

#ifndef ALUMNO_H
#define ALUMNO_H


#include "nota.h"
class alumno {
private:
    int codigo;
    char* nombre;
    int numcurso;
    int numaprobados;
    int numprimera;
    int numsegunda;
    int numtercera;
    class nota lnotas[100];
public:
    alumno();
    virtual ~alumno();
    void SetNombre(const char* cad);
    void SetCodigo(int codigo);
    void SetNumtercera(int numtercera);
    int GetNumtercera() const;
    void SetNumsegunda(int numsegunda);
    int GetNumsegunda() const;
    void SetNumprimera(int numprimera);
    int GetNumprimera() const;
    void SetNumaprobados(int numaprobados);
    int GetNumaprobados() const;
    void SetNumcurso(int numcurso);
    int GetNumcurso() const;
    int GetCodigo() const;
    void GetNombre(char *cad) const;
    void actulizar();
    //sobrecarga
    void operator += (const class nota& nt);
    
};

#endif /* ALUMNO_H */

