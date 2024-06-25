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
		int dniP, codM, horaI, horaF, minI, minF, segI, segF;
		double horaIni, horaFin, horaTotal, tarifa;
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
				horaIni = calcularHora(horaI, minI, segI);
				horaFin = calcularHora(horaF, minF, segF);
				horaTotal = horaFin - horaIni;
				tarifa = medico.GetTarifa();
				actualizarPaciente(paciente, tarifa, horaTotal);
				actualizarMedico(medico, tarifa, horaTotal);
			}
		}
	}
	
	public Paciente buscarPaciente(int dniP){
		int dni;
		for(Paciente pac: pacientes){
			dni = pac.GetDni();
			if(dni == dniP) return pac;
		}
		return null;
	}
	
	public Medico buscarMedico(int codM){
		int cod;
		for(Medico med: medicos){
			cod = med.GetCodigo();
			if(cod == codM) return med;
		}
		return null;
	}
	
	public double calcularHora(int hora, int min, int seg){
		double horaT;
		horaT = hora + ((double)min/60) + ((double)seg/3600);
		return horaT;
	}
	
	public void actualizarPaciente(Paciente paciente, double tarifa, 
			double horaTotal){
		int cantC;
		double tiempoTotal, gastosTotales;
		cantC = paciente.GetCantidadDeConsultas();
		tiempoTotal = paciente.GetTiempoTotal();
		gastosTotales = paciente.GetGastosTotales();
		double gastoActual = tarifa * horaTotal;
		cantC++;
		tiempoTotal += horaTotal;
		gastosTotales += gastoActual;
		paciente.SetCantidadDeConsultas(cantC);
		paciente.SetTiempoTotal(tiempoTotal);
		paciente.SetGastosTotales(gastosTotales);
	}
	
	public void actualizarMedico(Medico medico, double tarifa, double horaTotal){
		int cantC;
		double tiempoTotal, ingresosTotales;
		cantC = medico.GetCantidadDeConsultas();
		tiempoTotal = medico.GetTiempoTotal();
		ingresosTotales = medico.GetIngresosTotales();
		double ingresoActual = tarifa * horaTotal;
		cantC++;
		tiempoTotal += horaTotal;
		ingresosTotales += ingresoActual;
		medico.SetCantidadDeConsultas(cantC);
		medico.SetTiempoTotal(tiempoTotal);
		medico.SetIngresosTotales(ingresosTotales);
	}
	
	public void emitirReporteMedicos(){
		System.out.printf("%-6s %-40s %-20s %-10s %-12s %-12s %-5s\n", "CODIGO", 
				"NOMBRE", "ESPECIALIDAD", "TARIFA", "TIEMPO TOTAL", 
				"INGRESOS TOTALES", "CANTIDAD DE CONSULTAS");
		for(int i = 0; i < 150; i++){
			System.out.printf("=");
		}
		System.out.println();
		for(Medico med: medicos){
			med.imprimirMedico();
		}
		for(int i = 0; i < 150; i++){
			System.out.printf("-");
		}
		System.out.println();
	}
	
	public void emitirReportePacientes(){
		System.out.printf("%-10s %-40s %-30s %-12s %-14s %-5s \n", "DNI", "NOMBRE", 
				"DISTRITO", "TIEMPO TOTAL", "GASTOS TOTALES", 
				"CANTIDAD DE CONSULTAS");
		for(int i = 0; i < 150; i++){
			System.out.printf("=");
		}
		System.out.println();
		for(Paciente pac: pacientes){
			pac.imprimirPaciente();
		}
		for(int i = 0; i < 150; i++){
			System.out.printf("-");
		}
		System.out.println();
	}
}