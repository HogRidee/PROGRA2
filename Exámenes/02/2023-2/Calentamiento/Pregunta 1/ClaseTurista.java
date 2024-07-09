import java.util.Scanner;

class ClaseTurista extends Pasajero{
	private boolean valija;
	private boolean almuerzo;
	private double tarifaExtra;
	
	public ClaseTurista(){
		valija = false;
		almuerzo = false;
		tarifaExtra = 0.0;
	}
	
	public void SetValija(boolean val){
		valija = val;
	}
	
	public boolean GetValija(){
		return valija;
	}
	
	public void SetAlmuerzo(boolean alm){
		almuerzo = alm;
	}
	
	public boolean GetAlmuerzo(){
		return almuerzo;
	}
	
	public void SetTarifaExtra(double tarE){
		tarifaExtra = tarE;
	}
	
	public double GetTarifaExtra(){
		return tarifaExtra;
	}
	
	@Override
	public void leerPasajero(Scanner arch){
		super.leerPasajero(arch);
		String llevaValija;
		String pideAlmuerzo;
		llevaValija = arch.next();
		pideAlmuerzo = arch.next();
		if(llevaValija.compareTo("S") == 0) valija = true;
		if(pideAlmuerzo.compareTo("S") == 0) almuerzo = true;
		if(almuerzo) tarifaExtra += 55.90;
		if(valija) tarifaExtra += 85.50;
	}
	
	@Override
	public String GetTipo(){
		return "T";
	}
	
	@Override
	public void imprimirPasajero(){
		super.imprimirPasajero();
		System.out.printf("Articulos solicitados: ");
		System.out.printf("Valija: ");
		if(valija) System.out.printf("SI/ ");
		else System.out.printf("NO/ ");
		System.out.printf("Almuerzo: ");
		if(almuerzo) System.out.printf("SI/ ");
		else System.out.printf("NO/ ");
		System.out.printf("Tarifa Extra: %8.2f", tarifaExtra);
		System.out.println();
	}
}