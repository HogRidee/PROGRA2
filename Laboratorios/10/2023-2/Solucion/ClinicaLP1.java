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
		boolean finLectura = false;
		Medico medico;
		while(true){
			medico = new Medico();
			finLectura = medico.leerMedico(arch);
			if(finLectura) return;
			medicos.add(medico);
		}
	}
	
	public void leerPacientes(Scanner arch){
		boolean finLectura = false;
		Paciente paciente;
		while(true){
			paciente = new Paciente();
			finLectura = paciente.leerPaciente(arch);
			if(finLectura) return;
			pacientes.add(paciente);
		}
	}
	
	public void leerConsultas(Scanner arch){
		int dniP, codM, horaI, minI, segI, horaF, minF, segF;
		double tarifa, horaInicio, horaFin, duracionTotal;
		while(arch.hasNext()){
			dniP = arch.nextInt();
			codM = arch.nextInt();
			horaI = arch.nextInt();
			minI = arch.nextInt();
			segI = arch.nextInt();
			horaF = arch.nextInt();
			minF = arch.nextInt();
			segF = arch.nextInt();
			Paciente paciente = buscarPaciente(dniP);
			Medico medico = buscarMedico(codM);
			if(paciente != null && medico != null){
				tarifa = medico.GetTarifa();
				horaInicio = calcularTiempoHoras(horaI, minI, segI);
				horaFin = calcularTiempoHoras(horaF, minF, segF);
				duracionTotal = horaFin - horaInicio;
				actualizarPaciente(paciente, tarifa, duracionTotal);
				actualizarMedico(medico, duracionTotal);
			}
		}
	}
	
	private Paciente buscarPaciente(int dniP){
		for(Paciente pac: pacientes){
			if(pac.GetDni() == dniP) return pac;
		}
		return null;
	}
	
	private Medico buscarMedico(int codM){
		for(Medico med: medicos){
			if(med.GetCodigo() == codM) return med;
		}
		return null;
	}
	
	private double calcularTiempoHoras(int hora, int min, int seg){
		double horas;
		horas = hora + ((double)min/60) + ((double)seg/3600);
		return horas;
	}
	
	private void actualizarPaciente(Paciente paciente, double tarifa, 
			double duracionTotal){
		int cantC;
		double tiempoTotal, gastosTotales;
		tiempoTotal = paciente.GetTiempoTotal();
		gastosTotales = paciente.GetGastosTotales();
		cantC = paciente.GetCantidadDeConsultas();
		double gastoActual = tarifa * duracionTotal;
		tiempoTotal += duracionTotal;
		gastosTotales += gastoActual;
		cantC++;
		paciente.SetTiempoTotal(tiempoTotal);
		paciente.SetGastosTotales(gastosTotales);
		paciente.SetCantidadDeConsultas(cantC);
	}
	
	private void actualizarMedico(Medico medico, double duracionTotal){
		int cantC;
		double tarifa, tiempoTotal, ingresosTotales;
		tarifa = medico.GetTarifa();
		tiempoTotal = medico.GetTiempoTotal();
		ingresosTotales = medico.GetIngresosTotales();
		cantC = medico.GetCantidadDeConsultas();
		double ingresoActual = tarifa * duracionTotal;
		tiempoTotal += duracionTotal;
		ingresosTotales += ingresoActual;
		cantC++;
		medico.SetTiempoTotal(tiempoTotal);
		medico.SetIngresosTotales(ingresosTotales);
		medico.SetCantidadDeConsultas(cantC);
	}
	
	public void emitirReporteMedicos(){
		System.out.printf("%-20s %-27s %-19s %-8s %-8s %-12s %-5s\n", "CODIGO", 
				"NOMBRE", "ESPECIALIDAD", "TARIFA", "TIEMPO TOTAL", 
				"INGRESOS TOTALES", "CANTIDAD DE CONSULTAS");
		for(int i = 0; i < 150; i++){
			System.out.print("=");
		}
		System.out.println();		
		for(Medico med: medicos){
			med.imprimirMedico();
		}
		for(int i = 0; i < 150; i++){
			System.out.print("-");
		}
		System.out.println();		
	}
	
	public void emitirReportePacientes(){
		System.out.printf("%-20s %-27s %-21s %-9s %-8s %-12s\n", "DNI", 
				"NOMBRE", "DISTRITO", "TIEMPO TOTAL", "GASTOS TOTALES", 
				"CANTIDAD DE CONSULTAS");
		for(int i = 0; i < 150; i++){
			System.out.print("=");
		}
		System.out.println();		
		for(Paciente pac: pacientes){
			pac.imprimirPaciente();
		}
		for(int i = 0; i < 150; i++){
			System.out.print("-");
		}
		System.out.println();		
	}
}