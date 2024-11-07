
/* 
 * File:   Medico.h
 * Author: andre
 *
 * Created on 7 de Nov de 2024, 16:33
 */

#ifndef MEDICO_H
#define MEDICO_H

class Medico {
private:
    int codigo;
    char* nombre;
    char* especialidad;

public:
    Medico();
    virtual ~Medico();
    void SetEspecialidad(const char* cad);
    void GetEspecialidad(char *cad) const;
    void SetNombre(const char* cad);
    void GetNombre(char *cad) const ;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    
    //
    ;

};

#endif /* MEDICO_H */

