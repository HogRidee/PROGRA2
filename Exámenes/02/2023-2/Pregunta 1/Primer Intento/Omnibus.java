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
		asientosPC = 0;
		asientosCT = 0;
		pasajeros = new ArrayList<Pasajero>();
	}
	
	public void SetPlaca(String pla){
		placa = pla;
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
		String plac;
		String ciudad;
		plac = arch.next();
		if(plac.compareTo("FIN") == 0) return true;
		placa = plac;
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
		String destino;
		String tipo;
		destino = pasajero.GetDestino();
		tipo = pasajero.GetTipo();
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
		for(String dest: ruta){
			if(dest.compareTo(destino) == 0) return true;
		}
		return false;
	}
	
	public void imprimirDatos(){
		int n = 1;
		System.out.println("PLACA: " + placa);
		System.out.println("CHOFER: " + chofer);
		System.out.println("ASIENTOS LIBRES PC: " + asientosPC);
		System.out.println("ASIENTOS LIBRES CT: " + asientosCT);
		System.out.print("RUTA:");
		for(String ciudad: ruta){
			System.out.print(" " + ciudad);
		}
		System.out.println();
		System.out.println("PASAJEROS:");
		for(Pasajero pasajero: pasajeros){
			System.out.print(" " + n + ") ");
			pasajero.imprimirDatos();
			n++;
		}
		for(int i=0; i<90; i++){
			System.out.print("=");
		}
		System.out.println();
		System.out.println();
	}
}