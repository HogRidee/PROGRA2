import java.util.Scanner;

class Principal{
	public static void main(String [] arg){
		Empresa empresa = new Empresa();
		Scanner arch = new Scanner(System.in);
		empresa.leerBuses(arch);
		empresa.leerPasajeros(arch);
		empresa.emitirReporte();
	}
}