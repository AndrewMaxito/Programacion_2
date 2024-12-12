package pregunta01_programa_java;

import java.io.File;
import java.util.Scanner;

/**
 *
 * @author andre
 */
public class Pregunta01_Programa_java {

    public static void main(String[] args) throws Exception {
        // TODO code application logic here

        try {
            File archivo = new File("ArchDatosExamen.txt");
            Empresa empresa = new Empresa();
            Scanner arch = new Scanner(archivo);
            
            empresa.leerBuses(arch);
            empresa.ubicarPasajeros(arch);
            empresa.imprimirBuses(arch);
            
        } catch (Exception e) {
            System.out.println("e = " + e.getMessage()); //menciona el error
        }
    }

}
