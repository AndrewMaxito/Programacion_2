/* 
 * File:   main.cpp
 * Author: andre
 *
 * Created on 22 de mayo de 2024, 16:41
 */

#include <iostream>
#include <iomanip>

#include "Funciones.h"
#include "alumno.h"
#include "alumnonota.h"
using namespace std;

int main(int argc, char** argv) {
    alumno lalumnos[100];
    alumnonota lnotas[200];
    
    //a)
    cargaralumno(lalumnos);
    //b)
    carganotas(lnotas);
    //c)
    actulizarnotas(lalumnos,lnotas);
    //d)
    imprimealumnos(lalumnos);
    return 0;
}

