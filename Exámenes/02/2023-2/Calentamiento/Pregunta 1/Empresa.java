import java.util.ArrayList;
import java.util.Scanner;

class Empresa{
	private ArrayList <Omnibus> flota;
	
	public Empresa(){
		flota = new ArrayList<Omnibus>();
	}
	
	public void leerBuses(Scanner arch){
		Omnibus bus;
		boolean finDeLinea = false;
		while(true){
			bus = new Omnibus();
			finDeLinea = bus.leerBus(arch);
			if(finDeLinea) return;
			flota.add(bus);
		}
	}
	
	public void leerPasajeros(Scanner arch){
		Pasajero pasajero;
		String tipo;
		while(arch.hasNext()){
			tipo = arch.next();
			if(tipo.compareTo("P") == 0) pasajero = new PrimeraClase();
			else pasajero = new ClaseTurista();
			pasajero.leerPasajero(arch);
			for(Omnibus bus: flota){
				if(bus.sePuedeColocar(pasajero)) break;
			}
		}
	}
	
	public void emitirReporte(){
		System.out.println("EMPRESA DE TRANSPORTE DE PASAJEROS");
		System.out.println("REPORTE DE BUSES Y PASAJEROS");
		for(int i = 0; i < 100; i++)
			System.out.printf("=");
		System.out.println();
		for(Omnibus bus: flota){
			bus.imprimirBus();
			for(int i = 0; i < 100; i++)
				System.out.printf("=");
			System.out.println();
		}
	}
}