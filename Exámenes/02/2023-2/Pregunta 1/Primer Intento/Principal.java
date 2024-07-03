import java.util.Scanner;

class Principal{
	public static void main(String [] arg){
		Scanner arch = new Scanner(System.in);
		Empresa empresa = new Empresa();
		
		empresa.leerBuses(arch);
		empresa.leerPasajeros(arch);
		empresa.emitirReporte();
	}
}