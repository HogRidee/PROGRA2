import java.util.Scanner;

class Medico{
	private int codigo;
	private String nombre;
	private String especialidad;
	private double tarifa;
	private double tiempoTotal;
	private double ingresosTotales;
	private int cantidadDeConsultas;
	
	public Medico(){
		codigo = 0;
		tarifa = 0.0;
		tiempoTotal = 0.0;
		ingresosTotales = 0.0;
		cantidadDeConsultas = 0;
	}
	
	public Medico(int cod, String nomb, String esp, double tar, double tiempo, 
			double ingresos, int cantidadC){
		codigo = cod;
		nombre = nomb;
		especialidad = esp;
		tarifa = tar;
		tiempoTotal = tiempo;
		ingresosTotales = ingresos;
		cantidadDeConsultas = cantidadC;
	}
	
	public void SetCodigo(int cod){
		codigo = cod;
	}
	
	public int GetCodigo(){
		return codigo;
	}
	
	public void SetNombre(String nomb){
		nombre = nomb;
	}
	
	public String GetNombre(){
		return nombre;
	}
	
	public void SetEspecialidad(String esp){
		especialidad = esp;
	}
	
	public String GetEspecialidad(){
		return especialidad;
	}
	
	public void SetTarifa(double tar){
		tarifa = tar;
	}
	
	public double GetTarifa(){
		return tarifa;
	}
	
	public void SetTiempoTotal(double tiempo){
		tiempoTotal = tiempo;
	}
	
	public double GetTiempoTotal(){
		return tiempoTotal;
	}
	
	public void SetIngresosTotales(double ingresos){
		ingresosTotales = ingresos;
	}
	
	public double GetIngresosTotales(){
		return ingresosTotales;
	}
	
	public void SetCantidadDeConsultas(int cantidadC){
		cantidadDeConsultas = cantidadC;
	}
	
	public int GetCantidadDeConsultas(){
		return cantidadDeConsultas;
	}
	
	public boolean leerMedico(Scanner arch){
		int cod;
		cod = arch.nextInt();
		if(cod == 0) return true;
		codigo = cod;
		nombre = arch.next();
		especialidad = arch.next();
		tarifa = arch.nextDouble();
		return false;
	}
	
	public void imprimirMedico(){
		System.out.printf("%6d %-40s %-20s %6.2f %10.2f %13.2f %15d\n", codigo, 
			nombre, especialidad, tarifa, tiempoTotal, ingresosTotales, 
			cantidadDeConsultas);
	}
}