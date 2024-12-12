
package pregunta01_programa_java;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author andre
 */
public class Empresa {
    private ArrayList<Omnibus> flota;
    
    //Constructor
    public Empresa() {
        flota = new ArrayList<>();
    }
    
    public void leerBuses(Scanner arch){
        Omnibus omnibusAux;
        while (true) {
            omnibusAux = new Omnibus();
            if (!omnibusAux.leeDatos(arch))break;
            flota.add(omnibusAux);
        }
    }
    public void ubicarPasajeros(Scanner arch){
        Pasajero pasajero;
        String tipo;
        
        while (arch.hasNext()) {//Pregunta si existen lineas de datos
            tipo = arch.next();
            
            if (tipo.compareTo("P")==0) {
                pasajero = new PrimeraClase();
                
            } else {
                pasajero = new ClaseTurista();
            }
            //
            pasajero.leerDatos(arch);
            
            //Busco bus disponible para su ubicacion
            for (Omnibus omnibus : flota) {
                if (omnibus.sePuedeUbicar(pasajero))break; 
            }
        }
    }
    
    
    public void imprimirBuses(Scanner arch){
        System.out.println("Empresa de transporte Turistico");
        for (Omnibus omnibus : flota) {
            omnibus.imprimirDatos();
        }
    }
}
