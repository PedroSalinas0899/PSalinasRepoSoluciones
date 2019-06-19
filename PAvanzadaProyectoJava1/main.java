package proyecto1;

import java.util.Scanner;

public class main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int numero_naves;
		System.out.println("Bienvenidos a F-Zero!!!");	
		System.out.println("Ingrese la cantidad de naves contra las que quiere competir:");	
		numero_naves = sc.nextInt();
		
		carrera pista_carrera = new carrera(numero_naves);
	}
}