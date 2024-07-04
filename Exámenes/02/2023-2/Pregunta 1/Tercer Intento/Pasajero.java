import java.util.Scanner;

abstract class Pasajero{
	private int dni;
	private String nombre;
	private String destino;
	
	public Pasajero(){
		dni = 0;
	}
	
	public void SetDni(int d){
		dni = d;
	}
	
	public int GetDni(){
		return dni;
	}
	
	public void SetNombre(String nomb){
		nombre = nomb;
	}
	
	public String GetNombre(){
		return nombre;
	}
	
	public void SetDestino(String dest){
		destino = dest;
	}
	
	public String GetDestino(){
		return destino;
	}
	
	public void leerPasajero(Scanner arch){
		dni = arch.nextInt();
		nombre = arch.next();
		destino = arch.next();
	}
	
	public abstract String GetTipo();
	
	public void imprimirPasajero(){
		System.out.printf("DNI: %d NOMBRE: %-20s DESTINO: %-10s", dni, nombre, destino);
		System.out.println();
	}
} 