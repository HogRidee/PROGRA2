class PrimerProyecto{
	public static void main(String []arg){
		int a = 23;
		double x = 376.87;
		String nombre = "Juan Perez";
		boolean activo = true;
		Integer variable; //para array lista
		int cmp = nombre.compareTo("Maria");
		System.out.println("A = " + a);
		System.out.printf("A = %4d\n", a);
		System.out.println("X = " + x);
		System.out.println("Nombre = " + nombre);
		System.out.println("Activo = " + activo);
		if(cmp == 0) System.out.println("Iguales");
		else if(cmp > 0) System.out.println("Nombre es mayor que Maria");
		else System.out.println("Nombre es menor que Maria");
	}
}