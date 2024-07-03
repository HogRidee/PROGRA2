import java.util.ArrayList;
import java.util.Scanner;

class Empresa{
	private ArrayList <Omnibus> flota;
	
	public Empresa(){
		flota = new ArrayList<Omnibus>();
	}
	
	public void leerBuses(Scanner arch){
		boolean finDeLinea = false;
		Omnibus bus;
		while(true){
			bus = new Omnibus();
			finDeLinea = bus.leerBus(arch);
			if(finDeLinea) return;
			flota.add(bus);
		}
	}
	
	public void leerPasajeros(Scanner arch){
		String tipo;
		Pasajero pasajero;
		while(arch.hasNext()){
			tipo = arch.next();
			if(tipo.compareTo("P") == 0)
				pasajero = new PrimeraClase();
			else
				pasajero = new ClaseTurista();
			pasajero.leerDatos(arch);
			for(Omnibus bus: flota){
				if(bus.sePuedeUbicar(pasajero)) break;
			}
		}
	}
	
	public void emitirReporte(){
		System.out.println("EMPRESA DE SERVICIO TURISTICO");
		for(Omnibus bus: flota){
			bus.imprimirDatos();
		}
	}
}