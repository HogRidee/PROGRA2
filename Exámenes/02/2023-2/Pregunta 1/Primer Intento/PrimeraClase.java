import java.util.ArrayList;
import java.util.Scanner;

class PrimeraClase extends Pasajero{
	private ArrayList <String> articulosSolicitados;
	
	public PrimeraClase(){
		articulosSolicitados = new ArrayList<String>();
	}
	
	@Override
	public void leerDatos(Scanner arch){
		int numArticulos;
		String articulo;
		super.leerDatos(arch);
		numArticulos = arch.nextInt();
		for(int i = 0; i < numArticulos; i++){
			articulo = arch.next();
			articulosSolicitados.add(articulo);
		}
	}
	
	@Override
	public String GetTipo(){
		return "P";
	}
	
	@Override
	public void imprimirDatos(){
		super.imprimirDatos();
		System.out.print(" \"PRIMERA CLASE\" EXTRAS: ");
		for(String articulo: articulosSolicitados){
			System.out.print(articulo + " ");
		}
		System.out.println();
	}
}