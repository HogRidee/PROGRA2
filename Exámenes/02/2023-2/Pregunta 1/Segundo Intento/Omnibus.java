import java.util.ArrayList;
import java.util.Scanner;

class Omnibus{
	private String placa;
	private String chofer;
	private ArrayList <String> ruta;
	private int asientosPC;
	private int asientosCT;
	private ArrayList <Pasajero> pasajeros;
	
	public Omnibus(){
		ruta = new ArrayList<String>();
		asientosCT = 0;
		asientosPC = 0;
		pasajeros = new ArrayList<Pasajero>();
	}
	
	public void SetPlaca(String plac){
		placa = plac;
	}
	
	public String GetPlaca(){
		return placa;
	}
	
	public void SetChofer(String chof){
		chofer = chof;
	}
	
	public String GetChofer(){
		return chofer;
	}
	
	public void SetAsientosPC(int asPC){
		asientosPC = asPC;
	}
	
	public int GetAsientosPC(){
		return asientosPC;
	}
	
	public void SetAsientosCT(int asCT){
		asientosCT = asCT;
	}
	
	public int GetAsientosCT(){
		return asientosCT;
	}
	
	public boolean leerBus(Scanner arch){
		String ciudad;
		placa = arch.next();
		if(placa.compareTo("FIN") == 0) return true;
		chofer = arch.next();
		while(!arch.hasNextInt()){
			ciudad = arch.next();
			ruta.add(ciudad);
		}
		asientosPC = arch.nextInt();
		asientosCT = arch.nextInt();
		return false;
	}
	
	public boolean sePuedeUbicar(Pasajero pasajero){
		String tipo;
		String destino;
		tipo = pasajero.GetTipo();
		destino = pasajero.GetDestino();
		if(pasaPor(destino)){
			if(tipo.compareTo("P") == 0 && asientosPC > 0){
				pasajeros.add(pasajero);
				asientosPC--;
				return true;
			}
			else if(tipo.compareTo("T") == 0 && asientosCT > 0){
				pasajeros.add(pasajero);
				asientosCT--;
				return true;
			}
		}
		return false;
	}
	
	public boolean pasaPor(String destino){
		for(String ciudad: ruta){
			if(destino.compareTo(ciudad) == 0) return true;
		}
		return false;
	}
	
	public void imprimirBus(){
		System.out.println("PLACA: " + placa);
		System.out.println("CHOFER: " + chofer);
		System.out.printf("RUTA:");
		for(String ciudad: ruta){
			System.out.printf(" %s", ciudad);
		}
		System.out.println();
		System.out.println("ASIENTOS RESTANTES DE PRIMERA CLASE: " + asientosPC);
		System.out.println("ASIENTOS RESTANTES DE CLASE TURISTA: " + asientosCT);
		for(int i = 0; i < 150; i++){
			System.out.printf("-");
		}
		System.out.println();
		for(Pasajero pasajero: pasajeros){
			pasajero.imprimirPasajero();
		}
	}
}