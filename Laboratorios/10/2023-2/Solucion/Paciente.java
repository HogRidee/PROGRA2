import java.util.Scanner;

class Paciente{
	private int dni;
	private String nombre;
	private String distrito;
	private double tiempoTotal;
	private double gastosTotales;
	private int cantidadDeConsultas;
	
	public Paciente(){
		dni = 0;
		tiempoTotal = 0.0;
		gastosTotales = 0.0;
		cantidadDeConsultas = 0;
	}
	
	public Paciente(int d, String nomb, String dist, double tiempo, 
			double gastos, int cantC){
		dni = d;
		nombre = nomb;
		distrito = dist;
		tiempoTotal = tiempo;
		gastosTotales = gastos;
		cantidadDeConsultas = cantC;
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
	
	public void SetDistrito(String dist){
		distrito = dist;
	}
	
	public String GetDistrito(){
		return distrito;
	}
	
	public void SetTiempoTotal(double tiempo){
		tiempoTotal = tiempo;
	}
	
	public double GetTiempoTotal(){
		return tiempoTotal;
	}
	
	public void SetGastosTotales(double gastos){
		gastosTotales = gastos;
	}
	
	public double GetGastosTotales(){
		return gastosTotales;
	}
	
	public void SetCantidadDeConsultas(int cantC){
		cantidadDeConsultas = cantC;
	}
	
	public int GetCantidadDeConsultas(){
		return cantidadDeConsultas;
	}
	
	public boolean leerPaciente(Scanner arch){
		int d;
		d = arch.nextInt();
		if(d == 0) return true;
		dni = d;
		nombre = arch.next();
		distrito = arch.next();
		return false;
	}
	
	public void imprimirPaciente(){
		System.out.printf("%6d %-40s %-25s %6.2f %10.2f %15d\n", dni, 
			nombre, distrito, tiempoTotal, gastosTotales, 
			cantidadDeConsultas);
	}
}