import java.util.Scanner;
import java.util.Locale;

class Principal{
	private static ClinicaLP1 clinica = new ClinicaLP1();
	
	public static void main(String [] arg){
		Scanner arch = new Scanner(System.in).useLocale(Locale.US);
		clinica.leerMedicos(arch);
		clinica.leerPacientes(arch);
		clinica.leerConsultas(arch);
		clinica.emitirReporteMedicos();
		clinica.emitirReportePacientes();
	}
}