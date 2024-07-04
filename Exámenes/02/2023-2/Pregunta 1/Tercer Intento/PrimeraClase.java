import java.util.ArrayList;
import java.util.Scanner;

class PrimeraClase extends Pasajero{
	private ArrayList <String> articulosSolicitados;
	
	public PrimeraClase(){
		articulosSolicitados = new ArrayList<String>();
	}
	
	@Override
	public void leerPasajero(Scanner arch){
		String articulo;
		int nArticulos;
		super.leerPasajero(arch);
		nArticulos = arch.nextInt();
		for(int i = 0; i < nArticulos; i++){
			articulo = arch.next();
			articulosSolicitados.add(articulo);
		}
	}
	
	@Override
	public String GetTipo(){
		return "P";
	}
	
	@Override
	public void imprimirPasajero(){
		super.imprimirPasajero();
		System.out.printf("ARTICULOS SOLICITADOS: ");
		for(String articulo: articulosSolicitados){
			System.out.printf("%-10s ", articulo);
		}
		System.out.println();
	}
}