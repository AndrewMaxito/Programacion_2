#include <iostream>
#include <iomanip>
using namespace std;
#include "FuncionesDePunteros.h"

int main(int argc, char** argv) {
    char **nombres;
    int numDat;
    int arr[6]{6,7,3,1,5,2},Cant=6;
//    for (int i=0;i<Cant;i++)cout<<arr[i]<<" ";
    cout<<endl;
    ordenarNum(arr,0,Cant-1);
//    for (int i=0;i<Cant;i++)cout<<arr[i]<<" ";

//    leerNombres(nombres, numDat, "Personas.txt");
//    ordenar(nombres, 0, numDat - 1);
//    imprimir(nombres, numDat, "Reporte.txt");
    return 0;
}