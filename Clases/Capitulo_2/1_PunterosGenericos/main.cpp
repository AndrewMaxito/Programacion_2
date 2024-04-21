/* 
 * Proyecto: PunterosGenericos
 * Archivo: main.cpp
 * Autor: J. Miguel Guanira Erazo (Juan Miguel)
 *
 * Creado el 16 de mayo de 2020, 10:07 AM
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {
    void *ptV, **arrV;

    int a = 27, *ptA;
    double b = 54.71, *ptB;
    char nombre[50] = "Juan Gutierrez";

    /*--------------------------------------------------------------------------*/
    // ptA = &b;
    // ptB = &a; 

    /*--------------------------------------------------------------------------*/
    // ptV = &a;
    // ptV = &b;
    // ptV = nombre; 

    /*--------------------------------------------------------------------------*/
    //Esto si se puede hacer
    // ptV = new int;
    // ptV = new int[5];
    // ptV = new char*[5];

    /*--------------------------------------------------------------------------*/
    //     ptV = &a;
    //    // cout<<*ptV<<endl; //Esto no se puede hacer 
    //     cout<<*(int*)ptV<<endl; //Esto si se puede
    //     *(int*)ptV = 99;
    //     cout<<a<<endl;

    /*--------------------------------------------------------------------------*/

    // ptV = nombre;
    //// cout<<ptV[2]<<endl;
    // cout<<((char*)ptV)[3]<<endl;

    {
    }
    // arrV = ptV;
    // arrV = &a; //esto ocurre ya que **arrV no es un puntero genererico
    arrV = new void*[5]; //se crean 5  espacios de punteros genericos
    arrV[0] = &a; //arrV[0] si es un puntero genrerico
    *(int*) (arrV[0]) = 88; //Se le debe aplicar una operacion cast al arreglo como se muestra 
    cout << a << endl;
    return 0;

}

