package pregunta01_programa_java;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author andre
 */
public class Omnibus {

    private String placa;
    private String chofer;
    private final ArrayList<String> ruta;
    private int asinetosPC;
    private int asientosCT;
    private final ArrayList<Pasajero> pasajeros;

    public Omnibus() {
        //Inicializacion Importante
        ruta = new ArrayList<>();
        pasajeros = new ArrayList<>();
    }

    public boolean leeDatos(Scanner archivo) {
        placa = archivo.next();
        if (placa.compareTo("FIN") == 0) {
            return false;
        }
        chofer = archivo.next();
        //
        while (!archivo.hasNextInt()) {
            ruta.add(archivo.next());
        }
        asinetosPC = archivo.nextInt();
        asientosCT = archivo.nextInt();
        return true;
    }

    public boolean sePuedeUbicar(Pasajero pasajero) {
        String destino = pasajero.getDetino(), tipoPasajero = pasajero.getTipo();

        if (ruta.contains(destino)) {
            if (tipoPasajero.equals("P")) {
                if (asinetosPC > 0) {
                    pasajeros.add(pasajero);
                    asinetosPC--;
                    return true;
                }
            } else {
                if (asientosCT > 0) {
                    pasajeros.add(pasajero);
                    asientosCT--;
                    return true;
                }
            }
        }
        return false;
    }

    public void imprimirDatos() {
        System.out.printf("PLACA: %s\n", placa);
        System.out.printf("Chofer: %s\n", chofer);
        System.out.printf("Asinetos Libre PC: %3d\n", asinetosPC);
        System.out.printf("Asinetos Libre CT: %3d\n", asientosCT);
        System.out.print("RUTA:");
        for (String ciudad : ruta) {
            System.out.printf(" %s", ciudad);
        }
        System.out.println();
        System.out.println("PASAJEROS:");
        int n=1;
        for (Pasajero pasajero : pasajeros) {
            System.out.printf("%3d) ", n);
            pasajero.imprimirDatos();
            n++;
        }
        for (int i = 0; i < 90; i++) {
            System.out.print("=");
        }
        System.out.println();
        System.out.println();
    }

}
