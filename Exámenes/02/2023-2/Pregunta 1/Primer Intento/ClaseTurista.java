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
	public void leerDatos(Scanner arch){
		String llevaValija;
		String llevaAlmuerzo;
		super.leerDatos(arch);
		llevaValija = arch.next();
		llevaAlmuerzo = arch.next();
		if(llevaValija.compareTo("S") == 0) valija = true;
		else valija = false;
		if(llevaAlmuerzo.compareTo("S") == 0) almuerzo = true;
		else almuerzo = false;
		if(valija) tarifaExtra += 85.5;
		if(almuerzo) tarifaExtra += 55.90;
	}
	
	@Override
	public String GetTipo(){
		return "T";
	}
	
	@Override
	public void imprimirDatos(){
		super.imprimirDatos();
		System.out.print(" \"CLASE TURISTA\" EXTRAS: ");
		if(valija) System.out.print(" VALIJA");
		if(almuerzo) System.out.print(" ALMUERZO");
		System.out.println(" - TARIFA EXTRA: " + tarifaExtra);
	}
}