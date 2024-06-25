import java.util.Scanner;
import java.util.Locale;

class RedireccionamientoEntradaSalida{
	public static void main(String [] arg){
		Scanner arch = new Scanner(System.in).useLocale(Locale.US);
		int dni;
		double sueldo;
		char sexo;
		String nombre;
		String aux;
		while(arch.hasNext()){
			dni = arch.nextInt();
			System.out.printf("%10d\n", dni);
			aux = arch.next();
			sexo = aux.charAt(0);
			System.out.printf("%c\n", sexo);
			nombre = arch.next();
			System.out.printf("%-20s\n", nombre);
			sueldo = arch.nextDouble();
			System.out.printf("%10.2f\n", sueldo);
			System.out.printf("%10d %c %-20s %10.2f\n", dni, sexo, nombre, sueldo);
		}
	}
}