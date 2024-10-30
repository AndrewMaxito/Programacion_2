
/* 
 * File:   Espacio.h
 * Author: andre
 *
 * Created on 30 de octubre de 2024, 11:28
 */

#ifndef ESPACIO_H
#define ESPACIO_H

class Espacio {
public:
    Espacio();
    void SetPosy(int posy);
    int GetPosy() const;
    void SetPosx(int posx);
    int GetPosx() const;
    void SetContenido(char contenido);
    char GetContenido() const;
    
private:
    char contenido;
    int posx;
    int posy;
};

#endif /* ESPACIO_H */

