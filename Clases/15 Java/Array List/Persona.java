import java.util.Scanner;

class Persona{
	private int dni;
	private String nombre;
	private double sueldo;
	private char sexo;
	
	// Constructores
	public Persona(){
		sueldo = 0.0; // Ejemplo no obligatorio
	}
	
	public Persona(int dni, String nombre, double sueldo){
		this.dni = dni;
		this.nombre = nombre;
		this.sueldo = sueldo;
	}
	
	// Destructor
	// NO SE IMPLEMENTA, de eso se encarga el recolector de basura
	
	// Métodos selectores
	public void SetDni(int d){
		dni = d;
	}
	
	public int GetDni(){
		return dni;
	}
	
	public void SetSueldo(double s){
		sueldo = s;
	}
	
	public double GetSueldo(){
		return sueldo;
	}
	
	public void SetNombre(String n){
		nombre = n;
	}
	
	public String GetNombre(){
		return nombre;
	}
	
	public void imprimirDatos(){
		System.out.printf("%10d %-30s %10.2f\n", dni, nombre, sueldo);
	}
	
	public void leerDatos(Scanner arch){
		String aux;
		dni = arch.nextInt();
		aux = arch.next();
		sexo = aux.charAt(0);
		nombre = arch.next();
		sueldo = arch.nextDouble();
	}
}