
/* 
 * File:   nota.h
 * Author: andre
 *
 * Created on 22 de mayo de 2024, 10:19
 */

#ifndef NOTA_H
#define NOTA_H

class nota {
private:
    char* codcurso;
    int ciclo;
    int Nota;
public:
    nota();
    virtual ~nota();
    void SetNota(int Nota);
    void SetCiclo(int ciclo);
    void SetCodcurso(const char* cad);
    int GetNota() const;
    int GetCiclo() const;
    void GetCodcurso(char *) const;
    //
    void operator = (const class nota& nt);
    

};

#endif /* NOTA_H */

