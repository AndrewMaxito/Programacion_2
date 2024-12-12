package pregunta01_programa_java;

import java.util.Scanner;

/**
 *
 * @author andre
 */
public abstract class Pasajero {

    private int dni;
    private String nombre;
    private String detino;

    public void leerDatos(Scanner arch) {
        dni = arch.nextInt();
        nombre = arch.next();
        detino = arch.next();
    }

    public String getDetino() {
        return detino;
    }

    public abstract String getTipo();

    public void imprimirDatos() {
        System.out.printf("DNI: %10d Nombre: %-40s Destino: %-10s\n",
                dni, nombre, detino);
    }

}
