import java.util.ArrayList;
import java.util.Scanner;

class ClinicaLP1{
	private ArrayList <Medico> medicos;
	private ArrayList <Paciente> pacientes;
	
	public ClinicaLP1(){
		medicos = new ArrayList<Medico>();
		pacientes = new ArrayList<Paciente>();
	}
	
	public void leerMedicos(Scanner arch){
		boolean finDeLinea = false;
		Medico medico;
		while(true){
			medico = new Medico();
			finDeLinea = medico.leerMedico(arch);
			if(finDeLinea) return;
			medicos.add(medico);
		}
	}
	
	public void leerPacientes(Scanner arch){
		boolean finDeLinea = false;
		Paciente paciente;
		while(true){
			paciente = new Paciente();
			finDeLinea = paciente.leerPaciente(arch);
			if(finDeLinea) return;
			pacientes.add(paciente);
		}
	}
	
	public void leerConsultas(Scanner arch){
		
	}
	
	public void emitirReporteMedicos(){
		System.out.printf("%-10s %-40s %-20s %-12s %-12s %-12s %-5s \n", 
				"CODIGO", "NOMBRE", "ESPECIALIDAD", "TARIFA", "TIEMPO TOTAL", 
				"INGRESOS TOTALES", "CANTIDAD DE CONSULTAS");
		for(int i = 0; i < 150; i++){
			System.out.printf("=");
		}
		System.out.println();
		for(Medico med: medicos){
			med.imprimirMedico();
		}
		for(int i = 0; i < 150; i++){
			System.out.printf("=");
		}
		System.out.println();
	}
	
	public void emitirReportePacientes(){
		System.out.printf("%-10s %-40s %-30s %-12s %-12s %-5s \n", "DNI", 
				"NOMBRE", "DISTRITO", "TIEMPO TOTAL", "GASTOS TOTALES", 
				"CANTIDAD DE CONSULTAS");
		for(int i = 0; i < 150; i++){
			System.out.printf("=");
		}
		System.out.println();
		for(Paciente pac: pacientes){
			pac.imprimirPaciente();
		}
		for(int i = 0; i < 150; i++){
			System.out.printf("=");
		}
		System.out.println();
	}
}