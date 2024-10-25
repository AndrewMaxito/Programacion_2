
/* 
 * File:   alumnonota.h
 * Author: andre
 *
 * Created on 22 de mayo de 2024, 10:17
 */

#ifndef ALUMNONOTA_H
#define ALUMNONOTA_H

class alumnonota {
private:
    int codigo;
    char* codcurso;
    int cliclo;
    int nota;
public:
    alumnonota();
    alumnonota(const alumnonota& orig);
    virtual ~alumnonota();
    void SetNota(int nota);
    void SetCliclo(int cliclo);
    void SetCodcurso(const char* cad);
    void SetCodigo(int codigo);
    int GetNota() const;
    int GetCliclo() const;
    int GetCodigo() const;
    //
    void operator & (class nota &)const;
    

};

#endif /* ALUMNONOTA_H */

