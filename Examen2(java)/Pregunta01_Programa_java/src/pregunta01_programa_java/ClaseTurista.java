package pregunta01_programa_java;

import java.util.Scanner;

/**
 *
 * @author andre
 */
public class ClaseTurista extends Pasajero {

    private boolean valija;
    private boolean almuerzo;
    private double tarifaExtra;

    public ClaseTurista() {
        valija = false;
        almuerzo = false;
        tarifaExtra = 0;
    }

    @Override
    public void leerDatos(Scanner arch) {

        super.leerDatos(arch);
        //
        String SN = arch.next();
        if (SN.compareTo("S") == 0) {
            valija = true;
            tarifaExtra += 85.50;
        }
        SN = arch.next();
        if (SN.compareTo("S") == 0) {
            almuerzo = true;
            tarifaExtra += 55.90;
        }
    }

    @Override
    public String getTipo() {
        return "T";
    }

    @Override
    public void imprimirDatos() {
        super.imprimirDatos();
        System.out.print(" Pasajero de Clase Turista - Extras: ");
        if (valija == true) {
            System.out.print("Valija");
        }
        if (almuerzo == true) {
            System.out.print("Almuerzo");
        }
        System.out.printf("Tarifa extra: %10.2f\n", tarifaExtra);
    }

}
