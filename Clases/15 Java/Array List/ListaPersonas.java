import java.util.Scanner;
import java.util.Locale;
import java.util.ArrayList;

class ListaPersonas{
	private ArrayList <Persona> listaPersonas;
	
	public ListaPersonas(){
		listaPersonas = new ArrayList<Persona>();	
	}
	
	public void leerPersonas(){
		Scanner arch = new Scanner(System.in).useLocale(Locale.US);
		Persona persona;
	
		while(arch.hasNext()){
			persona = new Persona();
			persona.leerDatos(arch);
			listaPersonas.add(persona);
		}
	}
	
	public void mostrarDatos(){
		for(Persona per: listaPersonas){
			per.imprimirDatos();
		}
	}
}