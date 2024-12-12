package pregunta01_programa_java;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author andre
 */
public class PrimeraClase extends Pasajero {

    private final ArrayList<String> articulosSolicitados;

    public PrimeraClase() {
        articulosSolicitados = new ArrayList<>();
    }

    @Override
    public void leerDatos(Scanner arch) {

        super.leerDatos(arch);
        int numeroArticulos = arch.nextInt();
        for (int i = 0; i < numeroArticulos; i++) {
            articulosSolicitados.add(arch.next());
        }
    }

    @Override
    public String getTipo() {
        return "P";
    }

    @Override
    public void imprimirDatos() {
        super.imprimirDatos();
        System.out.print(" Pasajero de Priemra clase - Extras: ");
        for (String articulo : articulosSolicitados) {
            System.out.printf("%s ", articulo);
        }
        System.out.println();
    }

}
