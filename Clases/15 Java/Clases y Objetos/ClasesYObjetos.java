class ClasesYObjetos{
	public static void main(String [] arg){
		Persona persona;
		Persona persona2;
		Persona persona3;
		
		persona = new Persona(11111111, "Juan Perez", 3500.50);
		persona.imprimirDatos();
		
		persona2 = new Persona();
		persona2.SetDni(22222222);
		persona2.SetNombre("Ivan Araoz");
		persona2.SetSueldo(1050.50);
		persona2.imprimirDatos();
		
		persona3 = persona2;
		persona3.imprimirDatos();
		persona3.SetDni(33333333);
		persona3.imprimirDatos();
		persona2.imprimirDatos();
	}
}