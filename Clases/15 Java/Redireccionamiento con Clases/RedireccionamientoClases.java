import java.util.Scanner;
import java.util.Locale;

class RedireccionamientoClases{
	public static void main(String [] arg){
		Scanner arch = new Scanner(System.in).useLocale(Locale.US);
		Persona persona = new Persona();
		
		while(arch.hasNext()){
			persona.leerDatos(arch);
			persona.imprimirDatos();
		}
	}
}